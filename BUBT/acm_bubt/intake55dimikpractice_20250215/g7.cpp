/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
#include <cmath>
#include <iostream>
using namespace std;
#define ll long long
#define ld long double
#define el '\n'

#define HAS_TESTCASES

void sol() {
	ll n;
	cin >> n;
	ld r = floor(sqrt(n));
	cout << (r * r == n ? "YES" : "NO") << el;
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
