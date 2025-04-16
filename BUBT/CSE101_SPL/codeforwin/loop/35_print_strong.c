#include <stdio.h>

long long fact(int n) {
	long long fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}

int istrong(long long n) {
	long long tmp = n;

	long long sum = 0;
	while (n != 0) {
		sum += fact(n % 10);
		n /= 10;
	}
	return tmp == sum;
}

int main() {
	long long n = 145;
	scanf("%lld", &n);

	for (long long i = 1; i <= n; i++)
		if (istrong(i))
			printf("%lld ", i);

	return 0;
}
