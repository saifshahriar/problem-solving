package main

import (
	"bufio"
	"fmt"
	"math/rand"
	_ "math/rand" // The blank identifier (_) prevents the "unused import" error until you use it
	"os"
	"strconv"
	"strings"
)

const (
	lowerChars   = "abcdefghijklmnopqrstuvwxyz"
	upperChars   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	digitChars   = "0123456789"
	specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	fmt.Println("Welcome to the Random Password Generator")

	// Interactive Prompts (Already built for you):
	length := readInt(reader, "Enter password length (min 8) [Default 10]: ", 10)
	if length < 8 {
		fmt.Println("Length too short, defaulting to 8.")
		length = 8
	}

	useUpper := readBool(reader, "Include uppercase letters? (y/n) [Default y]: ", true)
	useDigits := readBool(reader, "Include digits? (y/n) [Default y]: ", true)
	useSymbols := readBool(reader, "Include symbols? (y/n) [Default n]: ", false)

	count := max(readInt(reader, "How many passwords to generate? [Default 1]: ", 1), 1)

	outPath := readString(
		reader,
		"Save to file? (Enter filename) [Default: output_1.txt]: ",
		"output_1.txt",
	)

	fmt.Println("\nGenerating...")

	// Execute Core Logic
	err := generateAndSavePasswords(count, length, useUpper, useDigits, useSymbols, outPath)
	if err != nil {
		fmt.Fprintf(os.Stderr, "Generation Error: %v\n", err)
		os.Exit(1)
	}
}

// --- Core Cryptographic Logic (YOUR TURN) ---

func randomCharFromSet(set string) byte {
	// TODO 1: Pick a random index from the 'set' string and return the character.
	return set[rand.Intn(len(set))]
}

func shuffle(b []byte) {
	// TODO 2: Randomize the order of the bytes in the slice.
	for i := len(b) - 1; i > 0; i-- {
		j := rand.Intn(i + 1)

		b[i], b[j] = b[j], b[i]
	}
}

func generatePassword(length int, upper, digits, symbols bool) string {
	// TODO 3: Build your character pool based on the boolean flags.
	pool := lowerChars
	var pass_str []byte

	// TODO 4: Guarantee at least one character from each selected pool is used.
	if upper {
		pass_str = append(pass_str, randomCharFromSet(upperChars))
		pool += upperChars
	}

	if digits {
		pass_str = append(pass_str, randomCharFromSet(digitChars))
		pool += digitChars
	}

	if symbols {
		pass_str = append(pass_str, randomCharFromSet(specialChars))
		pool += specialChars
	}

	// TODO 5: Fill the remaining length with random characters from your combined pool.
	for len(pass_str) < length {
		pass_str = append(pass_str, randomCharFromSet(pool))
	}

	// TODO 6: Shuffle the final password so the guaranteed characters aren't always at the front.
	shuffle(pass_str)

	return string(pass_str)
}

func evaluateStrength(pass_str string) int {
	// TODO 7: Write logic to score the password out of 5 based on its length.
	// Then use strings.ContainsAny() against upperChars, digitChars, and specialChars to check its actual complexity.
	score := 1
	if len(pass_str) >= 12 {
		score++
	}

	if len(pass_str) >= 16 {
		score++
	}

	f := []int{0, 0, 0} // upper, digits, symbols
	for _, c := range pass_str {
		s := string(c)

		if strings.ContainsAny(upperChars, s) {
			f[0] = 1
		}

		if strings.ContainsAny(digitChars, s) {
			f[1] = 1
		}

		if strings.ContainsAny(specialChars, s) {
			f[2] = 1
		}
	}

	cnt := f[0] + f[1] + f[2]

	if cnt >= 2 {
		score++
	}

	if cnt >= 3 {
		score++
	}

	return min(score, 5)
}

// --- High-Level Logic (YOUR TURN) ---

func generateAndSavePasswords(
	count, length int,
	upper, digits, symbols bool,
	outPath string,
) error {
	// TODO 8: Create a loop that runs 'count' times.
	var builder strings.Builder
	for range count {
		// TODO 9: Inside the loop, call generatePassword() and evaluateStrength().
		password := generatePassword(length, upper, digits, symbols)
		score := evaluateStrength(password)

		// TODO 10: Format the results nicely and store them in a single string.
		builder.WriteString(
			fmt.Sprintf("Password:  %-25s | Strength: %d/5\n", password, score),
		)
	}

	// TODO 11: Write that final string to the 'outPath' file.
	err := os.WriteFile(outPath, []byte(builder.String()), 0o644)
	if err != nil {
		return err
	}

	fmt.Printf("Successfully saved %d password(s) to '%s'\n", count, outPath)
	return nil
}

// --- Prompt Helpers (DO NOT MODIFY THESE FUNCTIONS) ---

func readString(reader *bufio.Reader, prompt string, defaultVal string) string {
	fmt.Print(prompt)
	input, _ := reader.ReadString('\n')
	input = strings.TrimSpace(input)
	if input == "" {
		return defaultVal
	}
	return input
}

func readInt(reader *bufio.Reader, prompt string, defaultVal int) int {
	input := readString(reader, prompt, "")
	if input == "" {
		return defaultVal
	}
	val, err := strconv.Atoi(input)
	if err != nil {
		fmt.Printf("Invalid number, using default (%d).\n", defaultVal)
		return defaultVal
	}
	return val
}

func readBool(reader *bufio.Reader, prompt string, defaultVal bool) bool {
	input := strings.ToLower(readString(reader, prompt, ""))
	if input == "" {
		return defaultVal
	}
	return input == "y" || input == "yes"
}
