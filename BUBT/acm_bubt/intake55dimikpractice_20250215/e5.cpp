#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 1; i <= t; ++i) {
		int n;
		cin >> n;

		vector<int> d;
		int         r = sqrt(n);

		for (int j = 1; j <= r; ++j) {
			if (n % j == 0) {
				d.push_back(j);
				if (j != n / j)
					d.push_back(n / j);
			}
		}

		sort(d.begin(), d.end());

		cout << "Case " << i << ": ";
		for (int j = 0; j < d.size(); ++j) {
			if (j > 0)
				cout << " ";
			cout << d[j];
		}
		cout << endl;
	}
	return 0;
}
