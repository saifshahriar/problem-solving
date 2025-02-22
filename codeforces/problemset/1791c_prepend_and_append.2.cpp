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
	int n;
	cin >> n;
	string s;
	cin >> s;

	int op = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1' && s[n - i - 1] == '0'
		    || s[i] == '0' && s[n - i - 1] == '1') {
			op++;
			continue;
		}
		break;
	}
	cout << (n - op * 2 <= 0 ? 0 : n - op * 2) << el;
	return 0;
}

// {{{
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
// }}}
