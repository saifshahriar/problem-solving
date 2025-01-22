#include <stdio.h>
#include <limits.h>

int main() {
	int num[3];
	scanf("%d %d %d", &num[0], &num[1], &num[2]);

	int res = INT_MIN;
	for (int i = 0; i < 3; ++i)
		if (res < num[i])
			res = num[i];

	printf("%d eh o maior\n", res);
    return 0;
}
