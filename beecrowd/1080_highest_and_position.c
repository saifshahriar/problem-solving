#include <stdio.h>
#include <limits.h>

int main() {
	int max_val = INT_MIN, index = -1;

	for (int i = 1; i <= 100; ++i) {
		int n;
		scanf("%d", &n);

		if (n > max_val) {
			max_val = n;
			index = i;
		}
	}

	printf("%d\n%d\n", max_val, index);
	return 0;
}
