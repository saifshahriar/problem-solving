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
	int n, x;
	cin >> n >> x;

	vector<int> v(n);
	for (auto& e : v)
		cin >> e;

	v.push_back(0);
	sort(v.begin(), v.end());

	int max_dist = 2 * abs(x - *max_element(v.begin(), v.end()));
	for (int i = 1; i < (int)v.size(); ++i) {
		int curr_dist = v[i] - v[i - 1];
		max_dist      = max(curr_dist, max_dist);
	}
	cout << max_dist << '\n';
}

int32_t main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
