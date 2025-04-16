#include <stdio.h>

int main() {
	int n = 11;
	scanf("%d", &n);

	int sieve[n + 1];
	for (int i = 0; i <= n; i++)
		sieve[i] = 1;
	sieve[0] = sieve[1] = 0;
	for (int i = 2; i * i <= n; i++)
		if (sieve[i])
			for (int j = i * i; j <= n; j += i)
				sieve[j] = 0;

	int sum = 0;
	for (int i = 0; i <= n; i++)
		sum += sieve[i] ? sieve[i] : 0;

	printf("%d\n", sum);
	return 0;
}
