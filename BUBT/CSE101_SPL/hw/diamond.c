#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n - i; ++j)
			printf(" ");
		for (int j = 1; j <= 2 * i - 1; ++j)
			printf("*");
		puts("");
	}

	n--;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j)
			printf(" ");
		for (int j = 2 * n - i; j >= i; --j)
			printf("*");
		puts("");
	}
	return 0;
}
