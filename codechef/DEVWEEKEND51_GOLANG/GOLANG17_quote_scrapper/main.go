package main

import (
	"encoding/json"
	_ "encoding/json" // The blank identifier (_) prevents the "unused import" error until you use it
	"fmt"
	"log"
	"net/http"
	_ "net/http" // Used for making network requests
	"os"
	"strings"
	_ "strings"
	"time"
	_ "time" // Used for polite scraping pauses

	"github.com/PuerkitoBio/goquery" // Used for parsing HTML docs
)

// Quote represents the structured data we want to extract
type Quote struct {
	Text   string   `json:"text"`
	Author string   `json:"author"`
	Tags   []string `json:"tags"`
}

var baseURL = "http://quotes.toscrape.com"

func main() {
	// 1. Setup CLI Input
	tagFilter := ""
	if len(os.Args) > 1 {
		tagFilter = os.Args[1]
	}

	if tagFilter == "" {
		fmt.Println("Starting full scrape of all quotes...")
	} else {
		fmt.Println("Starting scrape for tag: " + tagFilter)
	}

	// 2. Determine URL & Start Scrape
	startURL := buildStartingURL(tagFilter)

	allQuotes, err := scrapeAllPages(startURL)
	if err != nil {
		log.Fatalf("\nScraping failed: %v\n", err)
	}

	// 3. Export Data
	fmt.Println("\n\nScraping complete. Exporting to JSON...")
	err = exportToJSON(allQuotes, "quotes.json")
	if err != nil {
		log.Fatalf("Error saving file: %v\n", err)
	}

	fmt.Printf("Successfully saved %d quotes to quotes.json.\n", len(allQuotes))
}

// --- Step 1: Setup (YOUR TURN) ---

func buildStartingURL(tag string) string {
	// TODO 1: Check if the 'tag' string is empty.
	if tag != "" {
		// If it contains a tag value, construct and return the specific tag URL route starting from page 1.
		return baseURL + "/tag/" + tag + "/page/1/"
	}

	// If it is empty, construct and return the URL to scrape all pages starting from page 1.
	return baseURL + "/page/1/"
}

// --- Step 2: The Core Scraping Tools (YOUR TURN) ---

// fetchAndParsePage executes the HTTP GET request and loads the HTML into goquery
func fetchAndParsePage(url string) (*goquery.Document, error) {
	// TODO 2: Execute an http.Get request for the provided URL.
	res, err := http.Get(url)
	if err != nil {
		return nil, err
	}

	// TODO 3: Remember to defer closing the response body safely to prevent resource leaks.
	defer res.Body.Close()

	// TODO 4: Verify the server response status code is successful. If not, return a clear error.
	if res.StatusCode != http.StatusOK {
		return nil, fmt.Errorf("received status code %d", res.StatusCode)
	}

	// TODO 5: Convert the response body into a readable HTML document structure and return it for further processing.
	doc, err := goquery.NewDocumentFromReader(res.Body)
	if err != nil {
		return nil, err
	}

	return doc, nil
}

// extractTags grabs tags for a single quote block
func extractTags(s *goquery.Selection) []string {
	var tags []string

	// TODO 6: Target the HTML container matching the tags inside a quote block.
	s.Find(".tags .tag").Each(func(i int, r *goquery.Selection) {
		// TODO 7: Loop through each tag found, extract the inner text, sanitize it by trimming any extra whitespace, and append it into your tags slice.
		text := strings.TrimSpace(r.Text())
		if text != "" {
			tags = append(tags, text)
		}
	})

	return tags
}

// extractQuotesFromDoc isolates the DOM traversal logic to map HTML elements to our Go struct
func extractQuotesFromDoc(doc *goquery.Document) []Quote {
	var quotes []Quote

	// TODO 8: Isolate every HTML container representing an individual quote on the page.
	doc.Find(".quote").Each(func(i int, r *goquery.Selection) {
		// TODO 9: Inside the loop handler, extract the single quote text element and the author element.
		text := strings.TrimSpace(r.Find(".text").Text())
		author := strings.TrimSpace(r.Find(".author").Text())

		// TODO 10: Call your extractTags helper function passing the current quote selection block to resolve its tag list.
		tags := extractTags(r)

		if text == "" || author == "" {
			return
		}

		// TODO 11: Assemble a new Quote struct instance with the collected fields and append it into your collector slice.
		quote := Quote{
			Text:   text,
			Author: author,
			Tags:   tags,
		}
		quotes = append(quotes, quote)
	})

	return quotes
}

// getNextPageURL checks if there is a "Next" button and returns its link
func getNextPageURL(doc *goquery.Document) string {
	// TODO 12: Target the HTML element representation for the pagination next button link.
	var href string
	var exists bool
	doc.Find(".next a").Each(func(i int, r *goquery.Selection) {
		// TODO 13: Attempt to extract its hyperlinked URL reference attribute.
		href, exists = r.Attr("href")
	})

	// TODO 14: Check if the attribute exists. If it does not exist, return an empty string. Otherwise, return the extracted target link.
	if exists {
		return href
	}

	return ""
}

// --- Step 3: High-Level Orchestration (YOUR TURN) ---

// scrapeAllPages handles the pagination loop by combining the tools built above
func scrapeAllPages(startURL string) ([]Quote, error) {
	var allQuotes []Quote
	currentURL := startURL
	pageCount := 0

	for {
		// TODO 15: Call fetchAndParsePage for the current target iteration URL.
		gq, err := fetchAndParsePage(currentURL)
		if err != nil {
			return nil, err
		}

		// TODO 16: Call extractQuotesFromDoc to parse all the items extracted off the generated document structure.
		quotes := extractQuotesFromDoc(gq)

		// TODO 17: Append the newly collected list of items into your master collector array slice and increment pageCount.
		allQuotes = append(allQuotes, quotes...)
		pageCount++

		// In-Place Progress Indicator (\r overwrites the current line)
		fmt.Printf("\rScraped %d pages... (%d quotes collected)", pageCount, len(allQuotes))

		// TODO 18: Implement a hard safety limit. If pageCount is greater than 50, break the loop to prevent infinite spider traps.
		if pageCount > 50 {
			break
		}

		// TODO 19: Call getNextPageURL to discover if an additional pagination pathway exists on the document.
		nextPageUrl := getNextPageURL(gq)

		// TODO 20: If the pagination reference value returned is empty, break out of the processing loop.
		if nextPageUrl == "" {
			break
		}

		// TODO 21: Construct the absolute URL path combination by combining the primary base address string with the discovered route path stub.
		currentURL = baseURL + nextPageUrl

		// TODO 22: Introduce a brief pause delay of 500 milliseconds before starting the next page request cycle.
		time.Sleep(500 * time.Millisecond)

	}

	return allQuotes, nil
}

// --- Step 4: Final Export (YOUR TURN) ---

func exportToJSON(quotes []Quote, filename string) error {
	// TODO 23: Transform our populated master slice structure into a neatly formatted payload string.
	b, err := json.MarshalIndent(quotes, "", "\t")
	if err != nil {
		return err
	}

	// TODO 24: Write the generated structured byte payload out onto disk inside the specified filename target destination.
	var builder strings.Builder
	builder.WriteString(string(b))
	return os.WriteFile(filename, []byte(builder.String()), 0o644)
}
