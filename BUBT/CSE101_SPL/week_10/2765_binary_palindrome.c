#include <stdio.h>

#define MAX_LEN 101

int main() {
	char sentence[MAX_LEN];
	fgets(sentence, MAX_LEN, stdin);

	for (int i = 0; sentence[i] != '\0'; ++i)
		printf("%c", sentence[i] == ',' ? '\n' : sentence[i]);
	puts("");

	return 0;
}
