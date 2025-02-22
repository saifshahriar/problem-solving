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
#define sz(a) ((int)((a).size()))
#define char unsigned char
using namespace std;
#define el "\n"
// clang-format on
/// }}}

/*#define HAS_TESTCASES*/

int sol() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a == 1) {
			cout << "HARD" << el;
			return 0;
		}
	}
	cout << "EASY" << el;
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
