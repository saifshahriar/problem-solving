/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
#include <iostream>
using namespace std;
#define el    '\n'
#define sz(a) ((int)((a).size()))
#define HAS_TESTCASES

void sol() {
	string s;
	cin >> s;
	int n = sz(s);
	int i = s[n - 1] - '0';
	cout << (i % 2 == 0 ? "even" : "odd") << el;
}

int32_t main() {
	InTheNameofAllah
	int testcases = 1;
	// clang-format off
	#ifdef HAS_TESTCASES
	cin >> testcases;
	#endif
	for (int i = 1; i <= testcases; ++i)
		sol();
}
