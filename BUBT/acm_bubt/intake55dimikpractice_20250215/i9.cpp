#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int cnt = 0;
		while (n >= 5) {
			n   /= 5;
			cnt += n;
		}
		cout << cnt << endl;
	}
	return 0;
}
