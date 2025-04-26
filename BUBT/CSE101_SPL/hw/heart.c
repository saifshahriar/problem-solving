#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = n / 2; i <= n; i += 2) {
		for (int j = 1; j < n - i; j += 2)
			printf(" ");
		for (int j = 1; j <= i; j++)
			printf("*");
		for (int j = 1; j <= n - i; j++)
			printf(" ");
		for (int j = 1; j <= i; j++)
			printf("*");
		puts("");
	}

	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < n - i; j++)
			printf(" ");
		for (int j = 1; j <= (i * 2) - 1; j++)
			printf("*");
		puts("");
	}
	return 0;
}
