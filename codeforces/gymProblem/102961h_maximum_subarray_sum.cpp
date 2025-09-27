/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
#include <climits>
#include <iostream>
#include <vector>
#define el '\n'
using namespace std;
using ll = long long;

int32_t main() {
	InTheNameofAllah
	ll n;
	cin >> n;

	vector<ll> v(n);
	for (auto& e : v)
		cin >> e;

	ll cur = 0, mxs = LLONG_MIN;
	for (ll i = 0; i < n; ++i) {
		cur += v[i];
		mxs  = max(cur, mxs);

		if (cur < 0)
			cur = 0;
	}
	cout << mxs << el;
}
