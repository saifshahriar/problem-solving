#include <stdio.h>

const double PI = 3.14159;

int main() {
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	double triangulo = 0.5 * a * c,
		   circulo   = PI * c * c,
		   trapezio  = 0.5 * (a + b) * c,
		   quadrado  = b * b,
		   retangulo = a * b;

	printf("TRIANGULO: %0.3lf\n", triangulo);
	printf("CIRCULO: %0.3lf\n", circulo);
	printf("TRAPEZIO: %0.3lf\n", trapezio);
	printf("QUADRADO: %0.3lf\n", quadrado);
	printf("RETANGULO: %0.3lf\n", retangulo);
    return 0;
}
