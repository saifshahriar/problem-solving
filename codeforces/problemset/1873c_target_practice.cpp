/*
 * Author: Saif Shahriar
 */

#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

void sol() {
	int  n = 10;
	char dp[n][n];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> dp[i][j];

	int score = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (dp[i][j] == 'X') {
				int layer  = min({ i, j, abs(i - 9), abs(j - 9) });
				score     += layer + 1;
			}
	}
	cout << score << '\n';
}

int32_t main() {
	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
