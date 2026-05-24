package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"io"
	"net/http"
	"net/url"
	"os"
	"strconv"
	"strings"

	"github.com/joho/godotenv"
)

// --- 1. DATA MODELS (JSON Structs) ---

// SearchResponse models the JSON payload returned by the OMDb search API.
type SearchResponse struct {
	Search   []MovieShort `json:"Search"`
	Response string       `json:"Response"`

	// OMDb returns this field as a STRING, not an integer.
	TotalResults string `json:"totalResults"`
}

// MovieShort represents lightweight movie search results.
type MovieShort struct {
	ImdbID string `json:"imdbID"`
	Title  string `json:"Title"`
	Year   string `json:"Year"`
}

// MovieDetails represents the detailed movie response.
type MovieDetails struct {
	Title    string `json:"Title"`
	Plot     string `json:"Plot"`
	Director string `json:"Director"`
}

var baseURL = "http://www.omdbapi.com/"

// --- 2. ENTRY POINT ---

func main() {
	// Setup & Configuration
	apiKey := loadAPIKey()
	reader := bufio.NewReader(os.Stdin)

	// Initial User Query
	query := promptInitialSearch(reader)

	// Launch Interactive Movie Browser
	startREPL(query, apiKey, reader)
}

// --- 3. SETUP & INITIALIZATION ---

// loadAPIKey loads the OMDB_API_KEY environment variable.
func loadAPIKey() string {
	_ = godotenv.Load() // Ignore error and fall back to system env variables

	apiKey := os.Getenv("OMDB_API_KEY")
	if apiKey == "" {
		fmt.Println("Error: OMDB_API_KEY environment variable is missing.")
		os.Exit(1)
	}

	return apiKey
}

// promptInitialSearch captures the first movie search query.
func promptInitialSearch(reader *bufio.Reader) string {
	clearScreen()

	fmt.Println("=== CLI Movie Browser ===")
	fmt.Println("-----------------------------------")
	fmt.Print("Enter a movie to search for: ")

	query, _ := reader.ReadString('\n')
	query = strings.TrimSpace(query)

	if query == "" {
		fmt.Println("Search cannot be empty. Exiting.")
		os.Exit(1)
	}

	return query
}

// --- 4. CORE APPLICATION LOOP (REPL) ---
// startREPL launches the interactive movie browser loop.
func startREPL(query string, apiKey string, reader *bufio.Reader) {
	currentPage := 1

	for {
		clearScreen()

		fmt.Printf("Searching for '%s' (Page %d)...\n\n", query, currentPage)

		searchRes, err := fetchMovies(query, currentPage, apiKey)
		if err != nil {
			fmt.Printf("API Error: %v\n", err)
			os.Exit(1)
		}

		// OMDb returns Response = "False" if no matches exist
		if searchRes.Response == "False" {
			fmt.Println("No movies found or end of results.")
			break
		}

		printSearchResults(searchRes, currentPage)

		// Process user command and update REPL state
		var quit bool
		currentPage, quit = processCommand(apiKey, reader, currentPage)

		if quit {
			break
		}
	}
}

// processCommand handles CLI commands and returns:
// (updatedPageNumber, shouldQuit)
func processCommand(apiKey string, reader *bufio.Reader, currentPage int) (int, bool) {
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)

	// Normalize user input for easier comparisons
	lowerInput := strings.ToLower(strings.TrimSpace(input))

	// TODO 9:
	// Create a switch statement using lowerInput.
	switch lowerInput {
	// TODO 10:
	// Handle quit commands:
	// Cases: "q", "quit"
	//
	// Print:
	// Goodbye!
	//
	// Then return:
	// current page number (unchanged) and true to indicate the REPL should exit.
	case "q", "quit":
		fmt.Println("Goodbye!")
		return currentPage, true

		// TODO 11:
		// Handle next page navigation:
		// Cases: "n", "next"
		//
		// Increment currentPage.
	case "n", "next":
		currentPage++
		return currentPage, false

	// TODO 12:
	// Handle previous page navigation:
	// Cases: "p", "prev"
	//
	// Only decrement currentPage if it is greater than 1.
	case "p", "prev":
		if currentPage > 1 {
			currentPage--
		}
		return currentPage, false
	}

	// TODO 13:
	// Handle movie ID lookups.
	//
	// OMDb movie IDs begin with "tt"
	// Example:
	// tt0468569
	//
	// Check if the input begins with "tt".
	//
	// If it does:
	// Call displayMovieDetails().
	if strings.HasPrefix(lowerInput, "tt") {
		displayMovieDetails(lowerInput, apiKey, reader)
		return currentPage, false
	}
	//
	// Otherwise:
	// Print:
	// Invalid command. Press Enter to continue.
	fmt.Println("Invalid command. Press Enter to continue.")
	//
	// Then pause the REPL until the user presses Enter.
	reader.ReadString('\n')

	return currentPage, false
}

// --- 5. API & NETWORK REQUESTS (YOUR TURN) ---

// fetchMovies performs the OMDb search request.
func fetchMovies(query string, page int, apiKey string) (*SearchResponse, error) {
	// TODO 1:
	// Create a url.Values map.
	//
	// This map will hold our query parameters.
	params := url.Values{}

	// TODO 2:
	// Add the following query parameters:
	//
	// "apikey" -> apiKey
	// "s"       -> query
	// "page"    -> current page number
	//
	// IMPORTANT:
	// page is an integer.
	// Convert it into a string before adding it to the map.
	params.Add("s", query)
	params.Add("page", strconv.Itoa(page))
	params.Add("apikey", apiKey)

	// TODO 3:
	// Build the final request URL.
	//
	// Combine:
	// baseURL + "?" + params.Encode()
	//
	// Encode() automatically escapes spaces and special characters.
	reqUrl := baseURL + "?" + params.Encode()

	// TODO 4:
	// Execute the HTTP GET request.
	//
	// Then:
	// defer closing the response body.
	res, err := http.Get(reqUrl)
	if err != nil {
		return nil, err
	}

	defer res.Body.Close()

	// TODO 5:
	// Read the entire response body into a byte slice.
	body, err := io.ReadAll(res.Body)
	if err != nil {
		return nil, fmt.Errorf("failed to read response body: %w", err)
	}

	// TODO 6:
	// Create a SearchResponse variable.
	//
	// Then parse the response body into the struct.
	var result SearchResponse
	err = json.Unmarshal(body, &result)
	if err != nil {
		return nil, fmt.Errorf("failed to parse JSON: %w", err)
	}
	return &result, nil
}

// displayMovieDetails fetches and displays deep movie metadata.
func displayMovieDetails(id string, apiKey string, reader *bufio.Reader) {
	clearScreen()
	fmt.Println("Fetching deep details...")

	// TODO 7:
	// Create a new url.Values map.
	//
	// Add:
	// "apikey" -> apiKey
	// "i"      -> movie ID
	// "plot"   -> "full"
	params := url.Values{}
	params.Add("apikey", apiKey)
	params.Add("i", id)
	params.Add("plot", "full")

	// TODO 8:
	// Build the request URL.
	//
	// Execute the GET request.
	//
	// Defer closing the response body.
	//
	// Read the body bytes.
	//
	// Unmarshal the JSON into a MovieDetails struct.
	url := baseURL + "?" + params.Encode()
	res, err := http.Get(url)
	if err != nil {
		fmt.Printf("Network Error: %v\n", err)
		return
	}

	defer res.Body.Close()

	if res.StatusCode != http.StatusOK {
		fmt.Printf("Network Error: %v\n", err)
		return
	}

	body, err := io.ReadAll(res.Body)
	if err != nil {
		return
	}

	var details MovieDetails
	err = json.Unmarshal(body, &details)
	if err != nil {
		return
	}

	// --- UNCOMMENT THIS BLOCK AFTER YOUR STRUCT IS POPULATED ---

	clearScreen()

	fmt.Printf("MOVIE: %s\n", strings.ToUpper(details.Title))
	fmt.Printf("DIRECTOR: %s\n", details.Director)

	fmt.Println("-----------------------------------")

	fmt.Printf("PLOT:\n%s\n\n", details.Plot)

	fmt.Println("-----------------------------------")
	fmt.Print("Press Enter to return to the search list...")

	reader.ReadString('\n')
}

// --- 6. UI & TERMINAL HELPERS ---

// printSearchResults renders paginated movie results.
func printSearchResults(searchRes *SearchResponse, page int) {
	for _, m := range searchRes.Search {
		fmt.Printf("[ID: %-10s] %s (%s)\n", m.ImdbID, m.Title, m.Year)
	}

	fmt.Println("-----------------------------------")

	fmt.Printf("Page %d | Total Results: %s\n", page, searchRes.TotalResults)

	fmt.Println("Commands:")
	fmt.Println("[n]ext  -> Next page")
	fmt.Println("[p]rev  -> Previous page")
	fmt.Println("[q]uit  -> Exit")
	fmt.Println("[ID]    -> View movie details")

	fmt.Print("> ")
}

// clearScreen clears the terminal using ANSI escape codes.
func clearScreen() {
	fmt.Print("\033[H\033[2J")
}
