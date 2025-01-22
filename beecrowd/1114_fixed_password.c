#include <stdio.h>

void isvalid() {
	int pass;
	scanf("%d", &pass);

	if (pass != 2002) {
		printf("Senha Invalida\n");
		isvalid();
	} else
		printf("Acesso Permitido\n");
}

int main() {
	isvalid();
	return 0;
}
