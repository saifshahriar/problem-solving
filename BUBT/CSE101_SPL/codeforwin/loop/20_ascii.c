#include <stdio.h>

int main() {
	for (int i = 0; i <= 255; i++)
		printf("%d: %c\n", i, (char)i);
	return 0;
}
