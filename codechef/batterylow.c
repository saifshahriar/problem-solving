#include <stdio.h>

int main() {
	int t, x;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d", &x);
		printf(x <= 15 ? "YES\n" : "NO\n");
	}
	return 0;
}

/* https://www.codechef.com/problems/batterylow */
