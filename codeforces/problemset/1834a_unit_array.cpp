/*
 * Author: Saif Shahriar
 */

#include <algorithm>
#include <cmath>
#include <cstdint>
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

	long long prod    = accumulate(v.begin(), v.end(), 1LL, multiplies<int>());
	int       max_neg = (int)(v.size()) / 2;
	int       neg_cnt = count(v.begin(), v.end(), -1);
	int       ops     = neg_cnt > max_neg ? neg_cnt - max_neg : 0;
	sort(v.begin(), v.end());
	fill(v.begin(), v.begin() + ops, 1);
	prod = accumulate(v.begin(), v.end(), 1LL, multiplies<int>());
	cout << (prod == -1 ? ++ops : ops) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
