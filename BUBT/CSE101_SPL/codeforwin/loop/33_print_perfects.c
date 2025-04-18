#include <stdio.h>

int isperfect(int n) {
	int sum = 0;
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			sum += i;
	return sum;
}

int main() {
	int n = 1000;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		if (isperfect(i) == i)
			printf("%d ", i);

	return 0;
}
