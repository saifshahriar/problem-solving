#include <bits/stdc++.h>
using namespace std;

void sol() {
	int n, x;
	cin >> n >> x;

	vector<int> v(n);
	for (auto& e : v)
		cin >> e;

	for (int i = 0; i <= n; i++) {
		bool pos = true;

		for (int j = 0; j < n; j++) {
			bool act = (j >= i && j < i + x);
			if (v[j] == 1 && !act) {
				pos = false;
				break;
			}
		}

		if (pos) {
			cout << "YES\n";
			return;
		}
	}

	cout << "NO\n";
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
