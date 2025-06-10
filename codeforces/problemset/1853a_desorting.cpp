/*
 * Author: Saif Shahriar
 */

#include <climits>
#include <iostream>

using namespace std;

void sol() {
	int n;
	cin >> n;

	int curr = -1, prev = -1, mn = INT_MAX, diff = 0;
	cin >> curr;
	for (int i = 1; i < n; ++i) {
		prev = curr;
		cin >> curr;
		diff = curr - prev;
		mn   = min(mn, diff);
	}

	int ops = mn >= 0 ? (mn / 2) + 1 : 0;
	cout << ops << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
