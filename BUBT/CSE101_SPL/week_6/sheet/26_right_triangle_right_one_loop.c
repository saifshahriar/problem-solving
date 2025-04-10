/*
 * 26. Write a C programme to print the following shape only using one loop:
 *
 * Sample Input:
 * 4
 *
 * Sample Output:
 *     0
 *     00
 *     000
 *     0000
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1, cnt = 1; cnt <= n; ++i) {
		printf("0");

		if (i == cnt) {
			puts("");
			i = 0;
			cnt++;
		}
	}

	return 0;
}
