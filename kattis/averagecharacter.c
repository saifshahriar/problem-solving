#include <stdio.h>

int main() {
    char s[105];
    fgets(s, sizeof s, stdin);

    int sum = 0, i;
    for (i = 0; s[i] != '\0'; ++i)
        if (s[i] != '\n')
            sum += s[i];

	printf("%c\n", sum / (i - 1));
}
