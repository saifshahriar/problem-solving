#include <stdio.h>

int main() {
	int n = 7;
	scanf("%d", &n);

	int a = 0, b = 1;

	if (n >= 1)
		printf("%d ", a);
	if (n >= 2)
		printf("%d ", b);

	for (int i = 3; i <= n; ++i) {
		int c = a + b;
		printf("%d ", c);
		a = b;
		b = c;
	}

	puts("");
	return 0;
}
