/*
 * 20. Write a C programme to print a square box using '*'
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("*");
		}
		puts("");
	}
	return 0;
}
