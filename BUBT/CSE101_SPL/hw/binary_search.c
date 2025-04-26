#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	return (*(int *)a - *(int *)b);
}

int binary_search(int arr[], int n, int target) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (arr[m] == target)
			return m;
		else if (arr[m] < target)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

int main() {
	int n;
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	qsort(arr, n, sizeof(int), compare);

	int target;
	scanf("%d", &target);

	int idx = binary_search(arr, n, target);

	printf((idx != -1) ? "%d found at index: %d\n" : "not found\n", target, idx);

	return 0;
}
