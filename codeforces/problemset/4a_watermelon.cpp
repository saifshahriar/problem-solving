/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0); cin.tie(0);
#ifdef ONPC
	#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char
using namespace std;
#define el "\n"
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

/*#define HAS_TESTCASES*/

int sol() {
	int w; cin >> w;
	cout << ((w > 2 && w % 2 == 0) ? "YES" : "NO") << el;
	return 0;
}

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
			cout << "__________________________" << endl;
		#endif
	}
		#ifdef ONPC
			cerr << endl
				 << "took " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
		#endif
}