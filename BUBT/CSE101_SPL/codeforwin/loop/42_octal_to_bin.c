#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[10001] = "172";
	fgets(str, sizeof(str), stdin);

	int num = strtol(str, NULL, 8);
	printf("%b\n", num);
	return 0;
}
