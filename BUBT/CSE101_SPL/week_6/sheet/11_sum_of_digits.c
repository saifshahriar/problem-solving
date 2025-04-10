/* 11. Write a program to calculate the sum of the digits in a given number.
 *
 * Sample Input:                          Sample Output:
 * Enter a Number: 9012                   Sum = 12
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	n = n > 0 ? n : -n;

	int sum = 0;

	while (n >= 10) {
		sum += n % 10;
		n /= 10;
	}

	printf("Sum = %d\n", sum += n);
	return 0;
}
