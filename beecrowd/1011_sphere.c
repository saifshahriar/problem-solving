#include <stdio.h>

const double PI = 3.14159;

int main() {
	double r;
	scanf("%lf", &r);

	double formula = (4.0 / 3.0) * PI * r * r * r;
	printf("VOLUME = %0.3lf\n", formula);
	return 0;
}
