#include <stdio.h>

int main() {
	char *pattern[] = {
		"       A",
		"      B B",
		"     C   C",
		"    D     D",
		"   E       E",
		"    D     D",
		"     C   C",
		"      B B",
		"       A"
	};

	int size = sizeof(pattern) / sizeof(pattern[0]);

	for (int i = 0; i < size; ++i)
		printf("%s\n", pattern[i]);

	return 0;
}
