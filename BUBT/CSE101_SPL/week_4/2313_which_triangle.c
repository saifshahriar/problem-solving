#include <stdio.h>

#define el printf("\n");

int max(int a, int b) {
	return a > b ? a : b;
}

int pythagorean(int a, int b, int c) {
	return a * a + b * b == c * c;
}

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a + b <= c || a + c <= b || b + c <= a) {
		printf("Invalido\n");
		return 0;
	}

	if (a == b && b == c)
		printf("Valido-Equilatero");
	else if (a == b || b == c || a == c)
		printf("Valido-Isoceles");
	else
		printf("Valido-Escaleno");
	el;

	int ls = max(max(a, b), c);

	printf((ls == a && pythagorean(b, c, a)) ||
	       (ls == b && pythagorean(a, c, b)) ||
	       (ls == c && pythagorean(a, b, c)) ? "Retangulo: S" : "Retangulo: N");
	el;

	return 0;
}
