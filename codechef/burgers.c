#include <stdio.h>

int main(void) {
    int t, a, b;
    scanf("%d", &t);
	for (int i; i < t; i++) {
	    scanf("%d %d", &a, &b);
	    printf("%d\n", a > b ? b : a);
	}
	return 0;
}

/* https://www.codechef.com/problems/burgers */
