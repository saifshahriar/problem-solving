/*
 * 21. Write a C programme to print the following shape:
 *
 * Sample Input:
 * 4
 *
 * Sample Output:
 *     *
 *     **
 *     ***
 *     ****
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i + 1; ++j)
			printf("*");
		puts("");
	}
	return 0;
}
