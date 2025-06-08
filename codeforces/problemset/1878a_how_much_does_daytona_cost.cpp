/*
 * Author: Saif Shahriar
 */

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void sol() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (auto& e : v)
		cin >> e;

	cout << (count(v.begin(), v.end(), k) ? "YES" : "NO") << '\n';
}

int32_t main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
