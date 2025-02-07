#include <stdio.h>

const double PI = 3.14159;

int main() {
	double r;
	scanf("%lf", &r);
	printf("A=%0.4lf\n", PI * r * r);
	return 0;
}
