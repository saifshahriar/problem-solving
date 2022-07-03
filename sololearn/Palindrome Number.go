package main

import "fmt"

func reverseNumber(num int) int {
	res := 0
	for num>0 {
		remainder := num % 10
		res = (res * 10) + remainder
		num /= 10
   }
   return res
}

func main() {
	var isPalindrome int
	fmt.Scanln(&isPalindrome)
	if isPalindrome == reverseNumber(isPalindrome) {
		fmt.Println(isPalindrome, "is a Palindrome Number.")
	} else {
		fmt.Println(isPalindrome, "is not a Palindrome Number.")
	}
}
