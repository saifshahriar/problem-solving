#include <stdio.h>

static const int SIZE = 10;

int main() {
	char names[SIZE][31];
	for (int i = 0; i < SIZE; ++i)
		scanf("%31s", names[i]);
	puts(names[2]);
	puts(names[6]);
	puts(names[8]);
	return 0;
}
