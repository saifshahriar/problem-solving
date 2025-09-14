#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
	ll n;
	cin >> n;

	set<ll> s;
	for (int i = 0; i < n; ++i) {
		int e;
		cin >> e;
		s.insert(e);
	}

	cout << s.size() << endl;
}
