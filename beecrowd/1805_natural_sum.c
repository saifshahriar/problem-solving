// dont use loop here, it gives TLE. use series

#include <stdio.h>

int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);

	long long sum = (b * (b + 1) / 2) - (a * (a - 1) / 2);

	printf("%lld\n", sum);
	return 0;
}
