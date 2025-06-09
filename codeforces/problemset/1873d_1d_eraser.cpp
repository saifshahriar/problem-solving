/*
 * Author: Saif Shahriar
 */

#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

void sol() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int i = 0, ops = 0;
	while (i < n)
		if (s[i] == 'B') {
			++ops;
			i += k;
		} else
			i++;

	cout << ops << '\n';
}

int32_t main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
