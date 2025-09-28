/* prefix-sum
 *
 * keywords: contiguous subarray, maximum subarray sum, sum of subarray
 * see also: kadane
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int         n = 10;
	vector<int> v = { 1, 6, 9, 8, 55, 3, 14, 2, 7, 2 };

	// Prefix sum array
	vector<ll> ps(n + 1, 0);            // ps[0] = 0
	for (ll i = 1; i <= n; ++i)
		ps[i] = v[i - 1] + ps[i - 1];   // curr arr elem + prev sum elem

	// example: sum of subarray a[l..r] (0-based)
	ll l, r;
	cin >> l >> r;
	ll sum = ps[r + 1] - ps[l];
	cout << sum << '\n';
}
