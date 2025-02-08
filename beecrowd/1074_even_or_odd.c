#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int x;
		scanf("%d", &x);

		if (x == 0) {
			puts("NULL");
			continue;
		} else if (x % 2 == 0)
			printf("EVEN ");
		else
			printf("ODD ");

		puts(x > 0 ? "POSITIVE" : "NEGATIVE");
	}
	return 0;
}
