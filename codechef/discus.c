#include <stdio.h>

int
main(void)
{
	int t, x, y;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d %d", &x, &y);
		printf(y <= x * 107 / 100 ? "YES\n" : "NO\n");
	}
	return 0;
}

/* https://www.codechef.com/problems/discus */
