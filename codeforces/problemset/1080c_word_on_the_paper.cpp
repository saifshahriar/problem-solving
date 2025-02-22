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

#define HAS_TESTCASES

int sol() {
	char c;
	for (int i = 0; i < 8 * 8; ++i) {
		cin >> c;
		if (c != '.')
			cout << c;
	}
	cout << el;
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
	for (int i = 1; i <= testcases; ++i) {
		if (sol())
			break;
	}
}
// vim: foldmethod=marker
/// }}}
