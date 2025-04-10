/*
 * 9. Write a program to count the number of digits in a given number.
 *
 * Sample Input:                    Sample Output:
 * Enter a Number: 123452           Total digits: 6
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	n = n > 0 ? n : -n; // abs(n)

	int cnt = 1;
	while (n >= 10) {
		n /= 10;
		cnt++;
	}

	printf("Total digits: %d\n", cnt);
	return 0;
}
