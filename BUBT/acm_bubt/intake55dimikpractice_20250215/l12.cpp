/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define HAS_TESTCASES
#define el  '\n'
#define int long long

void sol() {
	int a, b;
	cin >> a >> b;
	cout << "LCM = " << (a * b) / gcd(a, b) << el;
}

int32_t main() {
	InTheNameofAllah
	// clang-format off
	int testcases = 1;
	#ifdef HAS_TESTCASES
	cin >> testcases;
	#endif
	for (int i = 1; i <= testcases; ++i)
		sol();
}
