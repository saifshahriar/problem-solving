#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& e : v)
		cin >> e;

	vector<int> u(k);
	for (auto& e : u)
		cin >> e;

	for (int i = 0; i < k; ++i) {
		int val = u[i];
		int l   = 0;
		int r   = n - 1;

		int flag = 0;

		while (l <= r) {
			int m = (l + r) / 2;
			if (v[m] == val) {
				flag = 1;
				break;
			} else if (val > v[m])
				l = m + 1;
			else if (val < v[m])
				r = m - 1;
		}

		cout << (flag ? "YES" : "NO") << endl;
	}
}
