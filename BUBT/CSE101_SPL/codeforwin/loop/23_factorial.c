#include<stdio.h>

int main() {
	long long fact= 1;
	long long n = 5;
	scanf("%lld", &n);

	for (int i = 1; i <= n; i++)
		fact *= i;
	printf("Factorial of %lld = %lld\n", n, fact);
	return 0;
}
