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
	int n, m;
	cin >> n >> m;

	vector<string> words(n);
	for (auto& e : words)
		cin >> e;

	int wc  = 0;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (wc + sz(words[i]) > m)
			break;
		wc += sz(words[i]);
		cnt++;
	}
	cout << cnt << el;
	return 0;
}

// {{{
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
// }}}
