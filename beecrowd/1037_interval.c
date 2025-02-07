#include <stdio.h>

int main() {
	float n;
	scanf("%f", &n);

	if (n >= 0 && n <= 100)
		printf("Intervalo ");
	else {
		printf("Fora de intervalo\n");
		return 0;
	}

	if (n <= 25)
		printf("[0,25]");
	else if (n <= 50)
		printf("(25,50]");
	else if (n <= 75)
		printf("(50,75]");
	else if (n <= 100)
		printf("(75,100]");
	printf("\n");
	return 0;
}
