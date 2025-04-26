#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	int min;
	int max = min = arr[0];
	for (int i = 0; i < n; i++) {
		if (arr[i] < min)
			min = arr[i];
		if (arr[i] > max)
			max = arr[i];
	}

	printf("Min: %d\n", min);
	printf("Max: %d\n", max);

	return 0;
}
