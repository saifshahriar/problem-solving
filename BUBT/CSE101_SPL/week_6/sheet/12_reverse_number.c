/* 12. Write a program to print the reverse of a given number.
 *
 * Sample Input:                          Sample Output:
 * Enter a Number: 231                    Reverse = 132
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	printf("Reverse = ");
	while (n >= 10) {
		printf("%d", n % 10);
		n /= 10;
	}
	printf("%d\n", n);
	return 0;
}
