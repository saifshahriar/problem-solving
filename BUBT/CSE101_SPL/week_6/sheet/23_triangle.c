/*
 * 23. Write a C programme to print the following shape:
 *
 * Sample Input:
 * 3
 *
 * Sample Output:
 *     *
 *    ***
 *   *****
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0, cnt = 1; i < n; ++i, cnt += 2) {
		for (int j = n - 1; j > i; --j)
			printf(" ");
		for (int j = 1; j <= cnt; ++j)
			printf("*");
		puts("");
	}
	return 0;
}
