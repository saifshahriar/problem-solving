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

	int i = 0, j = n - 1;

	while (i < j && s[i] != s[j])
		++i, --j;

	cout << j - i + 1 << '\n';
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
		#ifdef ONPC
		cout << i << ": ";
		#endif
		if (sol())
			break;
		#ifdef ONPC
		cout << "__________________________" << el;
		#endif
	}
	#ifdef ONPC
	cerr << el << "took " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << el;
	#endif
}

// vim: foldmethod=marker
// }}}
