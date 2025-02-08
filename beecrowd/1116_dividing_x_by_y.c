#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		float x, y;
		scanf("%f %f", &x, &y);
		printf(y == 0 ? "divisao impossivel\n" : "%0.1f\n", x / y);
	}
	return 0;
}
