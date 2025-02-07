#include <stdio.h>

int main() {
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	if (a + b > c && a + c > b && b + c > a)
		printf("Perimetro = %.1f", a + b + c);
	else
		printf("Area = %.1f", (a + b) * c / 2);
	printf("\n");
	return 0;
}
