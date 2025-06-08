/*
 * Author: Saif Shahriar
 */

#include <algorithm>
#include <climits>
#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

void sol() {
	int n;
	cin >> n;

	int mn = INT_MAX;
	while (n--) {
		int e;
		cin >> e;
		mn = min(abs(e), mn);
	}
	cout << mn << '\n';
}

int32_t main() {
	sol();
}
