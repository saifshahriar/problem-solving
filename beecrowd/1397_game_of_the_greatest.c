#include <stdio.h>

int main() {
	int t;
	while (scanf("%d", &t) == 1 && t != 0) {
		int n, cnt1 = 0, cnt2 = 0;
		while (t--) {
			int a = 0, b = 0;
			scanf("%d %d", &a, &b);
			a == b ? : a > b ? cnt1++ : cnt2++;
		}
		printf("%d %d\n", cnt1, cnt2);
	}
	return 0;
}
