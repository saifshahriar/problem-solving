/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0); cin.tie(0);
#include <iostream>
using namespace std;
#define el "\n"

int32_t main() {
	InTheNameofAllah
	int n;
	cin >> n;
	int sum = 0;
	while (n--) {
		string s;
		cin >> s;
		sum += (s == "X++" || s == "++X");
		sum -= (s == "X--" || s == "--X");
	}
	cout << sum << el;
	return 0;
}
