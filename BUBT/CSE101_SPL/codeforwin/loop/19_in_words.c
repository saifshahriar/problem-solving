#include <stdio.h>

int main() {
	char *num[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
	int   n = 3214;
	scanf("%d", &n);

	int reversed = 0;
	while (n) {
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}

	while (reversed) {
		printf("%s ", num[reversed % 10]);
		reversed /= 10;
	}
	return 0;
}
