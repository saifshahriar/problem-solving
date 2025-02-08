#include <stdio.h>

int main() {
	for (int h1, m1, h2, m2;
	    scanf("%d %d %d %d", &h1, &m1, &h2, &m2) && (h1 || m1 || h2 || m2);) {
		int curr = h1 * 60 + m1, alarm = h2 * 60 + m2;
		alarm += alarm < curr ? 24 * 60 : 0;
		printf("%d\n", alarm - curr);
	}
	return 0;
}
