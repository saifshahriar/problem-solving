/*
 * Author: Saif Shahriar
 */

#include <iostream>
using namespace std;

int32_t main() {
	int w;
	cin >> w;
	cout << (w > 2 && ~w & 1 ? "YES" : "NO") << '\n';
}
