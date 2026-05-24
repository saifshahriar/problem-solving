package main

import (
	"encoding/json"
	"fmt"
	"net/http"
	"strings"
	"sync"
	"time"

	"github.com/golang-jwt/jwt/v5"
	"golang.org/x/crypto/bcrypt"
)

// --- 1. DATA MODELS & GLOBALS ---

type Credentials struct {
	Username string `json:"username"`
	Password string `json:"password"`
}

type User struct {
	Username     string
	PasswordHash []byte
}

// TokenBlacklist safely stores invalidated tokens using a Read-Write Mutex
type TokenBlacklist struct {
	tokens map[string]bool
	mu     sync.RWMutex
}

var (
	// Secret key for JWT signing (In production, load this from .env file)
	jwtKey = []byte("f4a8b7e2c9d1f3a6b5e8c7d4a1f9e2b3")

	// mockDB simulates a database table for users
	mockDB = make(map[string]User)

	// blacklist instance
	blacklist = TokenBlacklist{
		tokens: make(map[string]bool),
	}
)

// --- 2. ENTRY POINT ---

func main() {
	// 1. Register the Public API routes
	http.HandleFunc("/register", RegisterHandler)
	http.HandleFunc("/login", LoginHandler)

	// 2. Register the Protected API routes (Wrapped in Auth Middleware)
	http.HandleFunc("/secret", authMiddleware(SecretHandler))
	http.HandleFunc("/logout", authMiddleware(LogoutHandler))

	fmt.Println("🚀 Server running on port 8080")

	err := http.ListenAndServe(":8080", nil)
	if err != nil {
		fmt.Printf("Server crashed: %v\n", err)
	}
}

// --- 3. BLACKLIST LOGIC (MUTEX) ---

// Add safely inserts a token into the blacklist using a Write Lock.
func (b *TokenBlacklist) Add(token string) {
	// TODO 1: Lock the mutex for writing
	b.mu.Lock()

	// TODO 2: Defer unlocking the mutex
	defer b.mu.Unlock()

	b.tokens[token] = true
}

// Contains safely checks if a token is blacklisted using a Read Lock.
func (b *TokenBlacklist) Contains(token string) bool {
	// TODO 3: Lock the mutex for reading
	b.mu.RLock()

	// TODO 4: Defer unlocking the read lock
	defer b.mu.RUnlock()

	return b.tokens[token]
}

// --- 4. ROUTE HANDLERS ---

// RegisterHandler accepts a username and password, hashes the password, and stores it.
func RegisterHandler(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
		return
	}

	var creds Credentials

	// TODO 5: Decode the JSON request body into the 'creds' variable.
	// If there is an error, return a 400 Bad Request.
	if err := json.NewDecoder(r.Body).Decode(&creds); err != nil {
		http.Error(w, "Bad Request", http.StatusBadRequest)
		return
	}

	// TODO 6: Check if the username already exists in 'mockDB'.
	// If it exists, return a 409 Conflict.
	if _, exists := mockDB[creds.Username]; exists {
		http.Error(w, "Conflict", http.StatusConflict)
		return
	}

	// TODO 7: Hash the password.
	// If there's an error, return a 500 Internal Server Error.
	hashedPassword, err := bcrypt.GenerateFromPassword([]byte(creds.Password), bcrypt.DefaultCost)
	if err != nil {
		http.Error(w, "Internal Server Error", http.StatusInternalServerError)
		return
	}

	// TODO 8: Store the new user in mockDB using the hashed password.
	mockDB[creds.Username] = User{
		Username:     creds.Username,
		PasswordHash: hashedPassword,
	}

	// TODO 9: Send a successful JSON response.
	// 1. Set the "Content-Type" header to "application/json"
	w.Header().Set("Content-Type", "application/json")

	// 2. Write a 201 StatusCreated header
	w.WriteHeader(http.StatusCreated)

	// 3. Return a JSON message: "User registered successfully"
	json.NewEncoder(w).Encode(map[string]string{
		"message": "User registered successfully",
	})
}

// LoginHandler verifies credentials and issues a JWT.
func LoginHandler(w http.ResponseWriter, r *http.Request) {
	if r.Method != http.MethodPost {
		http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
		return
	}

	var creds Credentials

	// TODO 10: Decode the JSON request body into 'creds'.
	if err := json.NewDecoder(r.Body).Decode(&creds); err != nil {
		return
	}

	// TODO 11: Look up the user in mockDB.
	// If they do not exist, return a 401 Unauthorized.
	user, exists := mockDB[creds.Username]
	if !exists {
		http.Error(w, "Unauthorized", http.StatusUnauthorized)
		return
	}

	// TODO 12: Compare the stored password hash with the provided password.
	// If it returns an error, return a 401 Unauthorized.
	if err := bcrypt.CompareHashAndPassword(
		[]byte(user.PasswordHash),
		[]byte(creds.Password),
	); err != nil {
		http.Error(w, "Unauthorized", http.StatusUnauthorized)
		return
	}

	// TODO 13: Generate the JWT token.
	// 1. Use jwt.NewWithClaims and the HS256 signing method.
	// 2. Set the "username" claim to the user's username.
	// 3. Set the "exp" (expiration) claim to 1 hour from time.Now().
	token := jwt.NewWithClaims(jwt.SigningMethodHS256, jwt.MapClaims{
		"username": creds.Username,
		"exp":      time.Now().Add(time.Hour).Unix(),
	})

	// TODO 14: Sign the token using the global 'jwtKey'.
	// If there is an error signing, return a 500 Internal Server Error.
	tokenString, err := token.SignedString(jwtKey)
	if err != nil {
		http.Error(w, "Internal Server Error", http.StatusInternalServerError)
		return
	}

	// TODO 15: Send the token back to the user.
	// 1. Set the "Content-Type" header to "application/json"
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(http.StatusOK)
	// 2. Return a JSON response: {"token": tokenString}
	json.NewEncoder(w).Encode(map[string]string{
		"token": tokenString,
	})
}

// SecretHandler returns a top-secret payload (only accessible if authenticated).
func SecretHandler(w http.ResponseWriter, r *http.Request) {
	message := map[string]string{
		"message": "CodeChef Contest Server: Hidden testcase archive unlocked.",
	}
	response, _ := json.Marshal(message)

	w.Header().Set("Content-Type", "application/json")
	w.Write(response)
}

// LogoutHandler extracts the current token and adds it to the blacklist.
func LogoutHandler(w http.ResponseWriter, r *http.Request) {
	// TODO 16: Extract the "Authorization" header from the request.
	authHeader := r.Header.Get("Authorization")
	if authHeader == "" {
		http.Error(w, "Missing Authorization header", http.StatusUnauthorized)
		return
	}

	// TODO 17: Extract just the token string by removing the "Bearer " prefix.
	token := strings.TrimPrefix(authHeader, "Bearer ")

	// TODO 18: Add the extracted token to the global blacklist.
	blacklist.Add(token)

	// TODO 19: Send a JSON response indicating successful logout.
	// Set the "Content-Type" header to "application/json"
	w.Header().Set("Content-Type", "application/json")
	w.WriteHeader(http.StatusOK)
	// Message: "Successfully logged out"

	json.NewEncoder(w).Encode(map[string]string{
		"message": "Successfully logged out",
	})
}

// --- 5. SECURITY MIDDLEWARE ---

// authMiddleware intercepts incoming requests, validates the JWT, and checks the blacklist.
func authMiddleware(next http.HandlerFunc) http.HandlerFunc {
	return func(w http.ResponseWriter, r *http.Request) {
		// TODO 20: Get the "Authorization" header.
		// If it is empty, return a 401 Unauthorized.
		authHeader := r.Header.Get("Authorization")
		if authHeader == "" {
			http.Error(w, "Unauthorized", http.StatusUnauthorized)
			return
		}

		// TODO 21: Extract the token string (trim the "Bearer " prefix).
		tokenString := strings.TrimPrefix(authHeader, "Bearer ")

		// TODO 22: Check if the token is in the blacklist.
		// If it is, return a 401 Unauthorized ("Token has been invalidated").
		if blacklist.Contains(tokenString) {
			http.Error(w, "Token has been invalidated", http.StatusUnauthorized)
			return
		}

		// TODO 23: Parse and validate the token.
		// Make sure to validate the signing method and return the global jwtKey.
		token, err := jwt.Parse(tokenString, func(token *jwt.Token) (interface{}, error) {
			if _, ok := token.Method.(*jwt.SigningMethodHMAC); !ok {
				return nil, fmt.Errorf("unexpected signing method")
			}

			return jwtKey, nil
		})

		// TODO 24: If the token parsing returns an error OR the token is not valid:
		// Return a 401 Unauthorized ("Invalid or expired token").
		if err != nil || !token.Valid {
			http.Error(w, "Invalid or expired token", http.StatusUnauthorized)
			return
		}

		// TODO 25: Token is valid. Pass the request to the actual handler.
		next.ServeHTTP(w, r)
	}
}
