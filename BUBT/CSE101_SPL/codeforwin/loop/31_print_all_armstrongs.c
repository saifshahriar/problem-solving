#include <stdio.h>
#include <math.h>

int isarmstrong(int n) {
	int tmp = n;

	int digits = 0;
	while (n != 0) {
		n /= 10;
		digits++;
	}

	n = tmp;

	int sum = 0;
	while (n != 0) {
		sum += pow(n % 10, digits);
		n /= 10;
	}

	return sum == tmp;
}

int main() {
	int n = 1000;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		if (isarmstrong(i))
			printf("%d ", i);
	return 0;
}
