/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0); cin.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int32_t main() {
	InTheNameofAllah
	int n;
	cin >> n;
	int sum = 0;
	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		sum += (a + b + c) >= 2;
	}
	cout << sum << el;
}
