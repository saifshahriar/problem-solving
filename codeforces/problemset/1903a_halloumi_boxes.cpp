/*
 * Author: Saif Shahriar
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

void sol() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (auto& e : v)
		cin >> e;

	vector<int> u = v;
	sort(u.begin(), u.end());

	cout << (u == v || k > 1 ? "YES" : "NO") << '\n';
}

int32_t main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
	return 0;
}
