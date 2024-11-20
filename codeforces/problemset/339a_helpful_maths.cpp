/*
 * Author: Saif Shahriar
 */

#include <algorithm>
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
	string s;
	cin >> s;
	string x;
	for (auto e : s) {
		if (e == '+')
			continue;
		x.push_back(e);
	}
	sort(x.begin(), x.end());
	s = "";
	for (auto e : x) {
		s.push_back(e);
		s.push_back('+');
	}
	s.pop_back();
	cout << s << el;
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

