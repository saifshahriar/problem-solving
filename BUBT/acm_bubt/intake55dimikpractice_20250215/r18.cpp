/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(), (v).end()
#define el     "\n"
#define sz(a)  ((int)((a).size()))

void sol() {
	int tt;
	cin >> tt;
	for (int i = 1; i <= tt; ++i) {
		vector<int> v(3);
		for (auto& e : v)
			cin >> e;
		sort(ALL(v));
		cout << "Case " << i << ": "
		     << (v[2] * v[2] == v[1] * v[1] + v[0] * v[0] ? "yes" : "no") << el;
	}
}

int32_t main() {
	InTheNameofAllah
	int testcases = 1;
	// clang-format off
	#ifdef HAS_TESTCASES
	cin >> testcases;
	#endif
	for (int i = 1; i <= testcases; ++i)
		sol();
}
