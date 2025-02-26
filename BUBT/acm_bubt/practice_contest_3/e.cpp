#ifdef ONPC
	#include <bits/_ojdebug.h>
	#define _GLIBCXX_DEBUG
	#define debug(x)       \
		cerr << #x << " "; \
		_print(x);         \
		cerr << endl;
#else
	#include <bits/stdc++.h>
	#define debug(x)
using namespace std;
#endif

#define int long long
#define el  '\n'

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONPC
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
#endif

	int n, q;
	cin >> n >> q;

	vector<int> cow1(n + 1, 0), cow2(n + 1, 0), cow3(n + 1, 0);

	for (int i = 1; i <= n; ++i) {
		int e;
		cin >> e;
		cow1[i] = cow1[i - 1] + (e == 1);
		cow2[i] = cow2[i - 1] + (e == 2);
		cow3[i] = cow3[i - 1] + (e == 3);
	}

	debug(cow1);
	debug(cow2);
	debug(cow3);

	while (q--) {
		int r, l;
		cin >> l >> r;
		cout << cow1[r] - cow1[l - 1] << " " << cow2[r] - cow2[l - 1] << " "
		     << cow3[r] - cow3[l - 1] << el;
	}

	return 0;
}
