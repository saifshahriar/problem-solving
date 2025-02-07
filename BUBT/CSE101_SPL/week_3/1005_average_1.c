#include <stdio.h>

int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);

	double weight_a = 3.5,
		   weight_b = 7.5,
		   media    = (a * weight_a + b * weight_b) / (weight_a + weight_b);

	printf("MEDIA = %.5lf\n", media);
	return 0;
}
