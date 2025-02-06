#include <stdio.h>

int main() {
	char d[3], m[3], y[3], dl;
	scanf("%2s %c %2s %c %2s", d, &dl, m, &dl, y);

	printf("%s/%s/%s\n", m, d, y);
	printf("%s/%s/%s\n", y, m, d);
	printf("%s-%s-%s\n", d, m, y);
	return 0;
}
