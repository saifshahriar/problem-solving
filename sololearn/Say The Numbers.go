// Saif Shahriar 💻✌🏼
/* Input three random integer numbers and it will output the numbers in word.
* Sample input:    2
				   0
				   6
* Sample output:   Two
				   Zero
				   Six
*/

package main

import "fmt"

func sayTheNum(x int) string {
	num := []string{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"}

	if x >= 0 && x <= 10 {
		return num[x]
	} else {
		return "😉"
	}
}

func main() {
	x := [3]int{}

	for i := 0; i <= 2; i++ {
		fmt.Scanln(&x[i])
	}
	for i := 0; i <= 2; i++ {
		fmt.Println(sayTheNum(x[i]))
	}
}
