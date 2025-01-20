#include <stdio.h>

int main() {
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	double weight_a = 2.0,
		   weight_b = 3.0,
		   weight_c = 5.0,
		   media    = (a * weight_a + b * weight_b + c * weight_c)
		            / (weight_a + weight_b + weight_c);

	printf("MEDIA = %0.1lf\n", media);
	return 0;
}
