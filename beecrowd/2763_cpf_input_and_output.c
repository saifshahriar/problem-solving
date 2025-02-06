#include <stdio.h>

int main() {
	char x[4], y[4], z[4], d[4], dl;
	scanf("%3s %c %3s %c %3s %c %3s", x, &dl, y, &dl, z, &dl, d);

	printf("%s\n", x);
	printf("%s\n", y);
	printf("%s\n", z);
	printf("%s\n", d);
    return 0;
}
