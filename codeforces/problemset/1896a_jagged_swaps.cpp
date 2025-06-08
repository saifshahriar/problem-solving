/*
 * Author: Saif Shahriar
 */

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool sorted(const vector<int>& v) {
	vector<int> tmp = v;
	sort(tmp.begin(), tmp.end());
	return tmp == v;
}

void sol() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (auto& e : v)
		cin >> e;

	vector<int> u = v;

	for (int i = 1; i < n - 1; ++i) {
		if (sorted(v)) {
			cout << "YES" << '\n';
			return;
		}
		if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
			swap(v[i], v[i + 1]);
			i = 0;
		}
	}

	cout << "NO" << '\n';
}

int32_t main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
