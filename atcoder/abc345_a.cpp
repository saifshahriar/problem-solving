/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
#ifdef ONPC
	#define _GLIBCXX_DEBUG
	#include <bits/_ojdebug.h>
	#define debug(x)       \
		cerr << #x << " "; \
		_print(x);         \
		cerr << endl;
#else
	#include <bits/stdc++.h>
	#define debug(x)
using namespace std;
#endif

#define el    '\n'
#define sz(a) ((int)((a).size()))

void sol() {
	string s;
	cin >> s;
	bool f = s[0] == '<' && s[sz(s) - 1] == '>';
	for (int i = 1; i < sz(s) - 1; ++i) {
		if (s[i] != '=') {
			f = false;
			break;
		}
	}
	cout << (f ? "Yes" : "No") << el;
}

int32_t main() {
	InTheNameofAllah
	sol();
}
