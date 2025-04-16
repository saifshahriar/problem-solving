#include <stdio.h>

int main() {
	int n = 2, p = 5;
	scanf("%d %d", &n, &p);

	int ans = 1;
	for (int i = 0; i < p; ++i)
		ans *= n;

	printf("%d\n", ans); // outputs: 32
	return 0;
}
