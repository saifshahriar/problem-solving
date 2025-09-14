#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
	ll n;
	cin >> n;

	n--;

	vector<ll> v(n);
	for (auto& e : v)
		cin >> e;

	sort(v.begin(), v.end());

	ll target = 1;
	for (int i = 0; i < n; ++i) {
		if (target != v[i]) {
			cout << target << endl;
			return 0;
		}
		target++;
	}

	cout << v[n - 1] + 1 << endl;
	return 0;
}
