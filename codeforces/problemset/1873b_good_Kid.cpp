/*
 * Author: Saif Shahriar
 */

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <functional>
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

	vector<long long> u(n);
	for (int i = 0; i < n; ++i) {
		int tmp = v[i];
		v[i]++;
		u[i] = accumulate(v.begin(), v.end(), 1LL, multiplies<long long>());
		v[i] = tmp;
	}

	cout << *max_element(u.begin(), u.end()) << '\n';
}

int32_t main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
