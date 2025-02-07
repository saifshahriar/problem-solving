#include <stdio.h>

int main() {
	char *output[] = {
		"---------------------------------------",
		"|                                     |",
		"|                                     |",
		"|                                     |",
		"|                                     |",
		"|                                     |",
		"---------------------------------------"
	};
	int size = sizeof(output) / sizeof(output[0]);

	for (int i = 0; i < size; ++i)
		puts(output[i]);

	return 0;
}
