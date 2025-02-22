#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	int f = 1;
	while (t--) {
		int n;
		cin >> n;
		if (!f)
			cout << '\n';
		f = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << '*';
			cout << '\n';
		}
	}
	return 0;
}
