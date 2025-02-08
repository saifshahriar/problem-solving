#include <stdio.h>

int main() {
	int a = 0, g = 0, d = 0;
	for (int inp; scanf("%d", &inp) == 1;) {
		switch (inp) {
			case 1:
				a++;
				break;
			case 2:
				g++;
				break;
			case 3:
				d++;
				break;
			case 4:
				goto end;
			default:
				continue;
		}
	}
end:
	puts("MUITO OBRIGADO");
	printf("Alcool: %d\n", a);
	printf("Gasolina: %d\n", g);
	printf("Diesel: %d\n", d);
	return 0;
}
