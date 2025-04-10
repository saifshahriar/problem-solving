/*
 * 29. Write a c-program to print the following shape. But in this program you can use only one loop.
 *
 * Input: 4
 * Output:
 * 1
 * 1 2
 * 1 2 3
 * 1 2 3 4
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1, cnt = 1; cnt <= n; ++i) {
		printf("%d ", i);

		if (i == cnt) {
			puts("");
			i = 0;
			cnt++;
		}
	}
	return 0;
}
