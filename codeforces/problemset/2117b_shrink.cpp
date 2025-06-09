#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;

void sol() {
	int n;
	cin >> n;

	cout << "1 ";
	for (int i = n; i >= 2; i--)
		cout << i << (i == 2 ? "\n" : " ");
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
