#include <cmath>
#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int pos, lift;
		cin >> pos >> lift;
		int res = 4 * abs(pos - lift) + 3 + 5 + 3 + 4 * pos + 3 + 5;
		printf("Case %d: %d\n", i, res);
	}
	return 0;
}
