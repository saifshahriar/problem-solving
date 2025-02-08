#include <stdio.h>

int main() {
	int t, arr[2001] = { 0 };
	scanf("%d", &t);

	while (t--) {
		int n;
		scanf("%d", &n);
		arr[n]++;
	}

	for (int i = 0; i < 2001; ++i) {
		if (arr[i] == 0)
			continue;
		printf("%d aparece %d vez(es)\n", i, arr[i]);
	}
	return 0;
}
