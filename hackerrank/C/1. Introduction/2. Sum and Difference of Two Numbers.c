#include <stdio.h>

int main() {
	int     intNum1, intNum2, intSum, intDif;
	float   floatNum1, floatNum2, floatSum, floatDif;

	scanf("%d %d\n", &intNum1, &intNum2);
	scanf("%f %f\n", &floatNum1, &floatNum2);

	intSum   = intNum1 + intNum2;
	intDif   = intNum1 - intNum2;
	floatSum = floatNum1 + floatNum2;
	floatDif = floatNum1 - floatNum2;

	printf("%d %d\n", intSum, intDif);
	printf("%0.1f %0.1f\n", floatSum, floatDif);

	return 0;
}