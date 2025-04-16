#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[101] = "1101110";
	fgets(str, sizeof(str), stdin);

	int num = strtol(str, NULL, 2);
	printf("%d\n", num);
	return 0;
}
