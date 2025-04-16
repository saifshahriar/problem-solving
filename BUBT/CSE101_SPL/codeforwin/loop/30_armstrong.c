#include <stdio.h>
#include <math.h>

int main() {
	int n = 371;
	scanf("%d", &n);

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

	puts(sum == tmp ? "armstrong" : "not armstrong");
	return 0;
}
