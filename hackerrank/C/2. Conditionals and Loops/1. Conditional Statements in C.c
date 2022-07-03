#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	char* index[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	printf("%s", (n <= 9) ? index[n-1] : "Greater than 9");
	return 0;
}