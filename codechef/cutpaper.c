#include <stdio.h>

int
main(void)
{
	int t;
	int n, k;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &k);
		int r = n/k;
		printf("%d\n", r*r);
	}
	return 0;
}

/* https://www.codechef.com/problems/cutpaper */
