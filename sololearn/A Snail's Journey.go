// Saif Shahriar 💻✌🏼

/* A Snail's Journey
	 Each day the snail climbs up A meters on a tree with H meters in height.
	 At night it goes down B meters.
	 Write a program which takes 3 inputs: H, A, B, and calculates how many days it will take for the snail to get to the top of the tree.
	 Assume H > A > B

* Input the value of H, A and B
* Sample Input:    15
										1
									0.5
* Sample Output:   29
*/

package main

import "fmt"

func main() {
	var H, A, B float64

	fmt.Scanln(&H)
		fmt.Scanln(&A)
		fmt.Scanln(&B)

		fmt.Println(int((H-B)/(A-B)))
}
