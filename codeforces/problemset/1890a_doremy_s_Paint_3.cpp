/*
 * Author: Saif Shahriar
 */

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool checkbalanced(const vector<int>& v) {
	set<int> s(v.begin(), v.end());
	auto     it   = s.begin();
	int      cnt1 = count(v.begin(), v.end(), *it);
	int      cnt2 = count(v.begin(), v.end(), *next(it));
	return cnt1 == cnt2 || abs(cnt1 - cnt2) == 1;
}

void sol() {
	int n;
	cin >> n;

	vector<int> v(n);
	for (auto& e : v)
		cin >> e;

	set<int> s(v.begin(), v.end());
	int      l = s.size();

	cout << (l == 1 || (l == 2 && (n == 3 || checkbalanced(v))) ? "Yes" : "No")
	     << '\n';
}

int32_t main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
