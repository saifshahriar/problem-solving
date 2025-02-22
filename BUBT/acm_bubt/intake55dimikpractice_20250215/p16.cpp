/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
#include <bits/stdc++.h>
using namespace std;

#define HAS_TESTCASES
#define int long long

void sol() {
	int n;
	cin >> n;
	int sum    = 0;
	int ex_sum = n * (n + 1) / 2;
	for (int i = 0; i < n - 1; ++i) {
		int e;
		cin >> e;
		sum += e;
	}
	cout << ex_sum - sum << endl;
}

int32_t main() {
	InTheNameofAllah
	int testcases = 1;
	// clang-format off
	#ifdef HAS_TESTCASES
	cin >> testcases;
	#endif
	for (int i = 1; i <= testcases; ++i) {
		sol();
	}
}
