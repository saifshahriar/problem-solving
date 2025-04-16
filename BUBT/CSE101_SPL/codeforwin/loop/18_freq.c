#include<stdio.h>

int main() {
	int n = 14782934;
	scanf("%d", &n);

	int freq[10];
	// populate the array with default value 0
	for (int i = 0; i <= 9; ++i)
		freq[i] = 0;

	while (n != 0) {
		freq[n % 10]++;
		n /= 10;
	}

	for (int i = 0; i <= 9; ++i)
		if (freq[i])
			printf("%d: %d\n", i, freq[i]);

	return 0;
}
