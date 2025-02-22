#include <stdio.h>

int main() {
	int cnt = 0;
	for (int i = 0; i < 6; ++i) {
		double a;
		scanf("%lf", &a);
		if (a > 0)
			cnt++;
	}
	printf("%d valores positivos\n", cnt);
	return 0;
}
