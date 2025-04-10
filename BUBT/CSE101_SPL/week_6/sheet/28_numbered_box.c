/*
 * 28. Write a c-program to print the following shape. But in this program you
 * can use only one loop.
 *
 * Input: 4
 * Output:
 * 1 2 3 4
 * 1 2 3 4
 * 1 2 3 4
 * 1 2 3 4
 *
 *
 * 1 1 1 1
 * 2 2 2 2
 * 3 3 3 3
 * 4 4 4 4
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int f = 0;
	for (int i = 1, cnt = 1; i <= n * n; ++i) {
		printf("%d ", cnt);

		if (!f && cnt == n) {
			puts("");
			cnt = 0;
		} else if (f && i == n) {
			puts("");
			cnt++;
		}

		if (!f && i == n * n) {
			f = 1;
			i = 0;
			cnt = 1;
			puts("\n");
		}

		if (!f)
			cnt++;
	}
	return 0;
}
