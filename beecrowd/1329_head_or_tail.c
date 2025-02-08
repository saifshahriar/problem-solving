#include <stdio.h>

int main() {
	for (int t; scanf("%d", &t) && t;) {
		int m = 0, j = 0;
		while (t--) {
			int a;
			scanf("%d", &a);
			a ? j++ : m++;
		}
		printf("Mary won %d times and John won %d times\n", m, j);
	}
	return 0;
}
