#include <stdio.h>

int main() {
	int x, y;
	scanf("%d %d", &x, &y);

	// swap(x, y)
	if (x > y) {
		int tmp = x;
		x = y;
		y = tmp;
	}

	int sum = 0;
	for (int i = ++x; i < y; ++i)
		if (i % 2 != 0)
			sum += i;
	printf("%d\n", sum);
	return 0;
}
