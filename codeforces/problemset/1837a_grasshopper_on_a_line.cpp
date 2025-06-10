/*
 * Author: Saif Shahriar
 */

#include <iostream>

using namespace std;

void sol() {
	int x, k;
	cin >> x >> k;
	cout
	    << (x % k != 0 ? "1\n" + to_string(x) : "2\n" + to_string(x - 1) + " 1")
	    << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
