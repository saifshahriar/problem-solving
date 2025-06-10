/*
 * Author: Saif Shahriar
 */

#include <iostream>
#include <stack>

using namespace std;

void sol() {
	int n;
	cin >> n;

	stack<int> s;
	int        ops = 0;
	for (int i = 0; i < n; ++i) {
		int e;
		cin >> e;

		if (!s.empty() && (~(s.top() ^ e) & 1)) {
			e *= s.top();
			s.pop();
			s.push(e);
			ops++;
		} else
			s.push(e);
	}
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
