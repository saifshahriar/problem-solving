#include <stdio.h>

int main() {
	int t, x, y;
	scanf("%d", &t);

	for(int i = 0; i < t; i++) {
		scanf("%d %d", &x, &y);
		printf((x >= y) ? "YES\n" : "NO\n");
	}
	return 0;
}

/* https://www.codechef.com/problems/manipulate */
