#include <bits/stdc++.h>
using namespace std;

int main() {
	float x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	float a = (x2 - x1) * (x2 - x1);
	float b = (y2 - y1) * (y2 - y1);

	float res = sqrt(a + b);

	printf("%0.4f\n", res);
	return 0;
}
