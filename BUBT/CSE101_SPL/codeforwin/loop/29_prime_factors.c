#include <stdio.h>

int main() {
	int n = 12;
	scanf("%d", &n);

	int sieve[n + 1];
	for (int i = 0; i <= n; i++)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;
	for (int i = 2; i * i <= n; i++)
		if (sieve[i])
			for (int j = i * i; j <= n; j += i)
				sieve[j] = 0;

	for (int i = 1; i <= n; ++i)
		if (n % i == 0 && sieve[i])
			printf("%d ", i);
	return 0;
}
