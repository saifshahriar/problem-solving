#include <stdio.h>

long long fact(int n) {
	long long fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}

int main() {
	long long n = 145;
	scanf("%lld", &n);

	long long tmp = n;

	long long sum = 0;
	while (n != 0) {
		sum += fact(n % 10);
		n /= 10;
	}

	puts(sum == tmp ? "strong" : "not strong");
	return 0;
}
