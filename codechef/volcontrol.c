#include <stdio.h>
#include <math.h>

int main(void) {
	int t;
	int x, y;

	scanf("%d", &t);

	for(int i = 0; i < t; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", abs(x-y));
	}

	return 0;
}

/* https://www.codechef.com/problems/volcontrol */
