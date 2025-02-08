#include <stdio.h>

int main() {
	for (char s[1001]; fgets(s, 1001, stdin);) {
		int balance = 0, correct = 1;
		for (int i = 0; s[i] != '\0' && s[i] != '\n'; ++i) {
			if (s[i] == '(')
				balance++;
			else if (s[i] == ')') {
				balance--;
				if (balance < 0) {
					correct = 0;
					break;
				}
			}
		}
		correct = !balance ?: 0;
		puts(correct ? "correct" : "incorrect");
	}
	return 0;
}
