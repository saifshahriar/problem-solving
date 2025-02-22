/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define el "\n"

void sol() {
	for (int i = 1000, cnt = 0; i >= 1; i--, cnt++) {
		cout << i;
		cout << ((cnt % 5 == 4 || i == 1) ? "\n" : " ");
	}
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
