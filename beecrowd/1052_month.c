#include <stdio.h>

int main() {
	int  n;
	char *months[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	};
	scanf("%d", &n);
	puts(months[--n]);
	return 0;
}
