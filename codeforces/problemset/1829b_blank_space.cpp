/*
 * Author: Saif Shahriar
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void sol() {
	int n;
	cin >> n;

	vector<int> v;
	int         i = 0, ops = 0;
	while (i < n) {
		int e;
		cin >> e;

		if (e == 1) {
			v.push_back(ops);
			ops = 0;
		} else
			ops++;
		i++;
	}
	v.push_back(ops);
	cout << *max_element(v.begin(), v.end()) << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
