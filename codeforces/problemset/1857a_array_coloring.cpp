/*
 * Author: Saif Shahriar
 */

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void sol() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (auto& e : v)
		cin >> e;

	if (v.size() == 2) {
		cout << (~(v[0] ^ v[1]) & 1 ? "YES" : "NO") << '\n';
		return;
	}

	int sum = accumulate(v.begin(), v.end(), 0);
	cout << (~sum & 1 ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
