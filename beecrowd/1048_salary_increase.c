#include <stdio.h>

int main() {
	float sal, new_sal, perc;
	scanf("%f", &sal);

	if (sal <= 400)
		perc = 15;
	else if (sal <= 800)
		perc = 12;
	else if (sal <= 1200)
		perc = 10;
	else if (sal <= 2000)
		perc = 7;
	else
		perc = 4;

	new_sal = sal + sal * perc / 100;

	printf("Novo salario: %0.2f\n", new_sal);
	printf("Reajuste ganho: %0.2f\n", new_sal - sal);
	printf("Em percentual: %d %%\n", (int)perc);
	return 0;
}
