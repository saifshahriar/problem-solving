#include <stdio.h>

int
main(void)
{
	int t, x;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d", &x);
		printf(x >= 30 ? "YES\n" : "NO\n");
	}
	return 0;
}

/* https://www.codechef.com/problems/timely */
