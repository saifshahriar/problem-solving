#include <stdio.h>

int main() {
	int n = 6;
	scanf("%d", &n);

	int sum = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			sum += i;

	puts(sum == n ? "perfect" : "not perfect");
	return 0;
}
