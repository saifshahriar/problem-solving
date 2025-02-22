/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
#include <iostream>
using namespace std;
#define HAS_TESTCASES
#define int long long

void sol() {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = a * b; i <= c; i += (a * b))
		if (i % a == 0 && i % b == 0)
			cout << i << '\n';
}

int32_t main() {
	InTheNameofAllah
	int testcases = 1;
	cin >> testcases;
	for (int i = 1; i <= testcases; ++i) {
		sol();
		/*if (i != testcases)*/
		cout << '\n';
	}
}
