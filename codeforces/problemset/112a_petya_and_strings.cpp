/*
 * Author: Saif Shahriar
 */

#include <cctype>
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
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; s1[i] != '\0'; ++i)
		s1[i] = tolower(s1[i]);
	for (int i = 0; s2[i] != '\0'; ++i)
		s2[i] = tolower(s2[i]);
	if (s1 < s2)
		cout << -1;
	else if (s1 > s2)
		cout << 1;
	else
		cout << 0;
	cout << el;
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

