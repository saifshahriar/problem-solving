/* 13. Write a program to check whether a given number is a palindrome or not.
 *
 * Sample Input:                          Sample Output:
 * Enter a Number: 404                    Palindrome
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, original, reversed = 0;
	scanf("%d", &n);

	original = abs(n);

	while (original) {
		reversed = reversed * 10 + original % 10;
		original /= 10;
	}

	if (reversed == abs(n))
		printf("Palindrome\n");
	else
		printf("Not a Palindrome\n");

	return 0;
}
