/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
/// {{{
// clang-format off
#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ALL(v) (v).begin(), (v).end()
#define INF INT_MAX
#define MOD 1000000007
#define SUM(v) (accumulate((v).begin(), (v).end(), 0))
#define el "\n"
#define sz(a) ((int)((a).size()))
#define char unsigned char
#define const constexpr
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// clang-format on
/// }}}

/*#define HAS_TESTCASES*/

int sol() {
	int x;
	cin >> x;

	if (x <= 5) {
		cout << 1 << el;
		return 0;
	}

	int steps = 0;
	while (x > 0) {
		if (x >= 5) {
			x -= 5;
			steps++;
		} else if (x == 4) {
			x -= 4;
			steps++;
		} else if (x == 3) {
			x -= 3;
			steps++;
		} else if (x == 2) {
			x -= 2;
			steps++;
		} else if (x == 1) {
			x -= 1;
			steps++;
		}
	}
	cout << steps << el;
	return 0;
}

/// {{{
// clang-format off
int32_t main() {
	InTheNameofAllah
	/* int testcases = 1e9; */
	int testcases = 1;
	#ifdef HAS_TESTCASES
	cin >> testcases;
	#endif
	for (int i = 1; i <= testcases; ++i)
		if (sol())
			break;
}
// vim: foldmethod=marker
/// }}}
