#include <stdio.h>

int main() {
	for (long long a, b; scanf("%lld %lld", &a, &b) == 2;)
		printf("%lld\n", a ^ b);
	return 0;
}
