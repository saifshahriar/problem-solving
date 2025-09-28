/* divisor
 */

#include <bits/stdc++.h>
using namespace std;

map<int, int> cntdivisors(int n, const vector<int>& v) {
	map<int, int> cnt;
	for (auto e : v) {
		int c = 0;
		for (int j = 1; j * j <= e; j++) {
			if (e % j == 0) {     // if j is a divisor of e
				c++;
				if (e / j != j)   // if j != counter divisor of e
					c++;
			}   // two checks at a time
		}
		cnt[e] = c;
	}
	return cnt;
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int           n        = 8;
	vector<int>   v        = { 12, 26, 24 };
	map<int, int> divisors = cntdivisors(n, v);
	for (auto& [key, val] : divisors)
		cout << key << ' ' << val << '\n';
}
