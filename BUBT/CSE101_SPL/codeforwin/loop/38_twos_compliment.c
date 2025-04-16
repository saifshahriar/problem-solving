#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[101] = "01101110";
	fgets(str, sizeof(str), stdin);

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '1')
			str[i] = '0';
		else if (str[i] == '0')
			str[i] = '1';

	int num = strtol(str, NULL, 2);
	printf("%b\n", num + 1);
	return 0;
}
