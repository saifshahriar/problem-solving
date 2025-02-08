#include <stdio.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);
	for (int i = 1; i <= y; ++i)
		printf("%d%s", i, (i % x == 0) ? "\n" : " ");
	return 0;
}
