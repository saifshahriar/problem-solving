#include <stdio.h>

int
main(void)
{
	int t;
	int x, y;
	int a;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &x, &y, &a);
		printf(a >= x && a < y ? "YES\n" : "NO\n");
	}
	return 0;
}


/* https://www.codechef.com/problems/agelimit */