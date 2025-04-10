/* 10. Write a program to calculate the sum of the first and the last digits in a given number.
 *
 * Sample Input:                          Sample Output:
 * Enter a Number: 403                    Sum = 7
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	n = n > 0 ? n : -n;

	int last = n % 10;

	while (n >= 10) {
		n /= 10;
	}

	printf("Sum = %d\n", n + last);
	return 0;
}
