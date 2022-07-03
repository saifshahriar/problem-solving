#include <stdio.h>
#include <math.h>

int main() {
	int n, tx, c, tc;

	/* n   = number of paint colours,
	 * tx  = tax,
	 * c   = cost (without tax),
	 * tc  = total cost (with tax),
	 */

	scanf("%d", & n);

	c = (40 + 5 * n);
	tx = ceil(c * 0.1); 	//The ceil function returns the smallest integer that is greater than or equal to x (ie: rounds up the nearest integer)
	tc = c + tx;

	printf("%d", tc);

	return 0;
}
