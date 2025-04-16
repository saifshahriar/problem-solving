#include <stdio.h>

int main() {
	char str[101] = "01101110";
	fgets(str, sizeof(str), stdin);

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '1')
			str[i] = '0';
		else if (str[i] == '0')
			str[i] = '1';

	puts(str);
	return 0;
}
