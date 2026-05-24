package main

import (
	"bufio"
	"encoding/csv"
	"fmt"
	"net"
	_ "net" // Remove "_" once you implement the DNS lookup TODO
	"os"
	"regexp"
	"strings"
	"sync"
)

// --- 1. DATA MODELS ---

type ValidationResult struct {
	Email       string
	SyntaxValid bool
	MXValid     bool
	Deliverable bool
}

// --- 2. ENTRY POINT ---

func main() {
	fmt.Println("=== Bulk Email Validator ===")

	// 1. Read input file
	emails := loadEmailsFromFile("emails.txt")
	if len(emails) == 0 {
		fmt.Println("No emails found to process. Exiting.")
		os.Exit(0)
	}

	fmt.Printf("Found %d emails to process.\n\n", len(emails))
	fmt.Println("Starting concurrent validation...")

	// 2. Process concurrently
	results := processEmailsConcurrent(emails)

	fmt.Printf("\nValidation complete. Processed %d emails\n\n", len(results))

	// 3. Export results
	fmt.Println("Exporting report to results.csv...")
	err := exportToCSV(results, "results.csv")
	if err != nil {
		fmt.Printf("Error saving report: %v\n", err)
		os.Exit(1)
	}

	fmt.Println("Success. Report saved.")
}

// --- 3. SETUP & FILE I/O ---

// loadEmailsFromFile reads a text file and returns a slice of strings.
func loadEmailsFromFile(filename string) []string {
	file, err := os.Open(filename)
	if err != nil {
		fmt.Printf("Error opening file: %v\n", err)
		os.Exit(1)
	}
	defer file.Close()

	var emails []string
	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		line := strings.TrimSpace(scanner.Text())
		if line != "" {
			emails = append(emails, line)
		}
	}

	return emails
}

// --- 4. VALIDATION LOGIC (YOUR TURN) ---

// checkSyntax uses Regex to ensure standard email formatting.
func checkSyntax(email string) bool {
	// TODO 1:
	// 1. Define this pattern: `^[a-zA-Z0-9._%+\-]+@[a-zA-Z0-9.\-]+\.[a-zA-Z]{2,}$`
	// 2. Compile it
	// 3. Return the boolean result of the regex match against the email
	pattern := `^[a-zA-Z0-9._%+\-]+@[a-zA-Z0-9.\-]+\.[a-zA-Z]{2,}$`
	re := regexp.MustCompile(pattern)
	return re.MatchString(email)
}

// checkDomain extracts the domain and queries the network for Mail Exchange (MX) records.
func checkDomain(email string) bool {
	// TODO 2:
	// 1. Split the email by "@".
	b := strings.Split(email, "@")

	// 2. If the resulting slice does not have exactly 2 parts, return false.
	if len(b) != 2 {
		return false
	}

	// 3. Extract the domain (the second part of the slice).
	domain := b[1]

	// 4. Query live DNS records.
	// 5. If the lookup returns an error, OR if the length of the returned records is 0, return false.
	dns_rec, err := net.LookupMX(domain)
	if err != nil || len(dns_rec) == 0 {
		return false
	}

	// 6. Otherwise, return true.
	return true
}

// validateEmail orchestrates the syntax and domain checks.
func validateEmail(email string) ValidationResult {
	result := ValidationResult{
		Email:       email,
		SyntaxValid: false,
		MXValid:     false,
		Deliverable: false,
	}

	// TODO 3: Orchestrate the checks
	// 1. Call checkSyntax(email). If it returns false, return the 'result' struct immediately.
	if !checkSyntax(email) {
		return result
	}

	// 2. Set syntax valid to true.
	result.SyntaxValid = true

	// 3. Call checkDomain(email). If it returns false, return the 'result' struct immediately.
	if !checkDomain(email) {
		return result
	}

	// 4. Set MX valid to true.
	result.MXValid = true

	// 5. If both passed, set deliverable to true and return the struct.
	result.Deliverable = true

	return result
}

// --- 5. CONCURRENT PIPELINE (YOUR TURN) ---

// processEmailsConcurrent uses Goroutines to validate emails in parallel.
func processEmailsConcurrent(emails []string) []ValidationResult {
	var results []ValidationResult

	var wg sync.WaitGroup
	var mu sync.Mutex

	for _, email := range emails {
		// TODO 4: Add 1 to the WaitGroup counter.
		wg.Add(1)

		// TODO 5: Launch a Goroutine
		go func(email string) { // Inside the Goroutine:
			// 1. Defer the WaitGroup Done() method to signal completion.
			defer wg.Done()

			// 2. Call validateEmail(email) and store the result.
			result := validateEmail(email)

			// TODO 6: Prevent Race Conditions
			// 3. Lock the Mutex
			mu.Lock()

			// 4. Append the result to the 'results' slice
			results = append(results, result)

			// 5. Unlock the Mutex
			mu.Unlock()
		}(email)
	}

	// TODO 7: Wait for all Goroutines to finish before continuing
	wg.Wait()

	return results
}

// --- 6. EXPORT (YOUR TURN) ---

// exportToCSV writes the validation results into a spreadsheet.
func exportToCSV(results []ValidationResult, filename string) error {
	file, err := os.Create(filename)
	if err != nil {
		return err
	}
	defer file.Close()

	writer := csv.NewWriter(file)
	defer writer.Flush()

	// TODO 8: Write the Header Row
	// 1. Create a slice of strings: "Email", "SyntaxValid", "MXValid", "Deliverable"
	header := []string{
		"Email", "SyntaxValid", "MXValid", "Deliverable",
	}

	// 2. Write it to the CSV file
	err = writer.Write(header)
	// 3. If it returns an error, return that error.
	if err != nil {
		return err
	}

	// TODO 9: Write the Data Rows
	// 1. Loop through the 'results' slice.
	for _, result := range results {
		// 2. For each result, create a slice of strings containing the fields.
		//  Hint: Use fmt.Sprint() to convert booleans to strings.
		row := []string{
			result.Email,
			fmt.Sprint(result.SyntaxValid),
			fmt.Sprint(result.MXValid),
			fmt.Sprint(result.Deliverable),
		}
		// 3. Write the row to the CSV
		err = writer.Write(row)
		// 4. If it returns an error, return that error.
		if err != nil {
			return err
		}
	}

	return nil
}
