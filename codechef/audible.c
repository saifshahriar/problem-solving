#include <stdio.h>

int
main(void)
{
	int t;
	int x;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &x);
		printf(x >= 67 && x <= 45000 ? "YES\n" : "NO\n");
	}
}

/* https://www.codechef.com/problems/audible */