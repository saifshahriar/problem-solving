#include <stdio.h>

int main() {
	int a, b;
	char* g[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	scanf("%d\n%d", &a, &b);

	for (int i = a; i >= a && i <= b; i++) {
		printf("%s\n", (i >= 1 && i <= 9) ? g[i-1] : (i % 2 == 0) ? "even" : "odd");
	}

	return 0;
}