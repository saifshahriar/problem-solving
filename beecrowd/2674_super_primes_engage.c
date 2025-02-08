#include <stdio.h>

int isprime(int n) {
	if (n < 2)
		return 0;
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return 0;
	return 1;
}

int issupp(int n) {
	while (n >= 10) {
		int d = n % 10;
		n /= 10;
		if (isprime(d) == 0)
			return 0;
	}
	if (n == 2 || n == 3 || n == 5 || n == 7)
		return 1;
	return 0;
}

int main() {
	int n;
	while(scanf("%d", &n) == 1)
		puts(isprime(n) ? issupp(n) ? "Super" : "Primo" : "Nada");
	return 0;
}
