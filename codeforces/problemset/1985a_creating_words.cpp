/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
/// {{{
#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char  unsigned char
using namespace std;
#define el "\n"
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
/// }}}

#define HAS_TESTCASES

int sol() {
	string a, b;
	cin >> a >> b;
	swap(a[0], b[0]);
	cout << a << " " << b << el;
	return 0;
}

// {{{
// clang-format off
int32_t main() {
	InTheNameofAllah;
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
// }}}
