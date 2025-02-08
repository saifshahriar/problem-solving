#include <stdio.h>
#include <limits.h>

int main() {
	for (int m, n; scanf("%d %d", &m, &n) == 2 && m > 0 && n > 0;) {
		int mx = m > n ? m : n,
			mn = m < n ? m : n,
			sum = 0;
		for (int i = mn; i <= mx; ++i) {
			printf("%d ", i);
			sum += i;
		}
		printf("Sum=%d\n", sum);
	}
	return 0;
}
