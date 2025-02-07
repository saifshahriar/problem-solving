#include <stdio.h>

int main() {
	int  n, a, b;
	char o;
	scanf("%d %d %c %d", &n, &a, &o, &b);
	printf(o == '+' && a + b <= n
		|| o == '*' && a * b <= n
		? "OK\n" : "OVERFLOW\n");
	return 0;
}
