#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int leds[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 },
			cnt = 0;

		char led[1001];
		scanf("%s", led);

		for (int i = 0; led[i] != '\0'; ++i)
			cnt += leds[led[i] - '0'];

		printf("%d leds\n", cnt);
	}
	return 0;
}
