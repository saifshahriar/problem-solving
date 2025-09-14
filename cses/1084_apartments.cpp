#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
/// {{{ Helper
// clang-format off
#ifdef ONPC
#include <bits/_ojdebug.h>
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#include <bits/stdc++.h>
#define debug(x)
using namespace std;
#endif

/* macros */
#define el       '\n'
#define sz(a)    ((int)((a).size()))

/* typedefs */
#define ll  long long
#define ull unsigned long long
#define ld  long double

/* templates */
template<typename Container> auto sum(const Container &c) {
	using T = typename decay<decltype(*c.begin())>::type;
	return accumulate(c.begin(), c.end(), T{0});
}

template<typename Container> auto prod(const Container &c) {
	using T = typename decay<decltype(*c.begin())>::type;
	return accumulate(c.begin(), c.end(), T{0}, multiplies<>());
}

// clang-format on
/// }}}

/* #define HAS_TESTCASES */
/* #define PRINTCASES */

void sol() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> a(n);
	for (auto& e : a)
		cin >> e;

	vector<int> b(m);
	for (auto& e : b)
		cin >> e;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int cnt = 0;
	for (int i = 0, j = 0; i < n && j < m;) {
		if (b[j] < a[i] - k)
			j++;
		else if (b[j] > a[i] + k)
			i++;
		else {
			cnt++;
			i++;
			j++;
		}
	}
	cout << cnt << el;
}

/// {{{ Main
// clang-format off
int32_t main() {
	InTheNameofAllah
	int testcases = 1;
	#ifdef HAS_TESTCASES
	cin >> testcases;
	#endif
	for (int i = 1; i <= testcases; ++i) {
		#ifdef PRINTCASES
		cout << "Case " << i << ": ";
		#endif
		sol();
	}
}
// vim: foldmethod=marker
/// }}}
