#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[1001] = "6E";
	scanf("%s", str);

	int num = strtol(str, NULL, 16);
	printf("%o\n", num);
	return 0;
}
