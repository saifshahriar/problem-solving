#include <stdio.h>

int main() {
	int nums[] = {2, 3, 4, 5},
		muls[] = {0, 0, 0, 0};

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		int bn;
		scanf("%d", &bn);
		for (int j = 0; j < sizeof(nums) / sizeof(nums[0]); ++j) {
			if (bn % nums[j] == 0)
				muls[j]++;
		}
	}

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
		printf("%d Multiplo(s) de %d\n", muls[i], nums[i]);

	return 0;
}
