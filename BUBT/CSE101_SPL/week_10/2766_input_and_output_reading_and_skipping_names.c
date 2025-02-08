#include <stdio.h>

#define SIZE 10
#define MAX_LEN 31

int main() {
	char names[SIZE][MAX_LEN];
	for (int i = 0; i < SIZE; ++i)
		scanf("%s", names[i]);

	puts(names[2]);
	puts(names[6]);
	puts(names[8]);
	return 0;
}
