#include <stdio.h>

int main(void) {
    int t, x;
    scanf("%d", &t);
	for (int i; i < t; i++) {
	    scanf("%d", &x);
	    printf("%d\n", (x*2*5));
	}
	return 0;
}

/* https://www.codechef.com/problems/fit */
