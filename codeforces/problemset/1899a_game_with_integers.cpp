/*
 * Author: Saif Shahriar
 */

#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

void sol() {
	int n;
	cin >> n;
	cout << (n % 3 ? "First" : "Second") << '\n';
}

int32_t main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
