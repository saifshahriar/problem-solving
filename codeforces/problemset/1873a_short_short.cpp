/*
 * Author: Saif Shahriar
 */

#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

void sol() {
	string s;
	cin >> s;
	cout << (s[0] == 'a' || s[1] == 'b' || s[2] == 'c' ? "YES" : "NO") << '\n';
}

int32_t main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
