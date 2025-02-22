#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<int> lp(n), rp(m);

		for (int i = 0; i < n; i++)
			cin >> lp[i];

		for (int i = 0; i < m; i++)
			cin >> rp[i];

		int cnt = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (lp[i] + rp[j] <= k)
					cnt++;

		cout << cnt << endl;
	}

	return 0;
}
