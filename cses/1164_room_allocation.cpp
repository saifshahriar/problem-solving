/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
/// {{{ Helper
// clang-format off
#ifdef ONPC
// #define _GLIBCXX_DEBUG
#include <bits/_ojdebug.h>
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#include <bits/stdc++.h>
#define debug(x)
using namespace std;
#endif

/* macros */
#define el              '\n'
#define len(x)          ((int)((x).size()))
#define all(x)          (x).begin(), (x).end()
#define rall(x)         (x).rbegin(), (x).rend()
#define getbit(n, i)    (((n) & (1LL << (i))) != 0)
#define setbit0(n, i)   ((n) & (~(1LL << (i))))
#define setbit1(n, i)   ((n) | (1LL << (i)))
#define togglebit(n, i) ((n) ^ (1LL << (i)))
#define lsb(n)          ((n) & (-(n)))
#define msb_pos(n)      ((x) == 0 ? -1 : 31 - __builtin_clzll(x))
#define yes             puts("yes")
#define Yes             puts("Yes")
#define YES             puts("YES")
#define no              puts("no")
#define No              puts("No")
#define NO              puts("NO")

/* typedefs */
#define int long long
#define ll  long long
#define ull unsigned long long
#define ld  long double

/* constants */
constexpr int       MOD   = 1e9 + 7;
constexpr int       MX    = 2e5 + 5;
constexpr long long INF   = 1e18;
constexpr int       N     = 2e5 + 5;
constexpr double    EPS   = 1e-9;
constexpr int       dx[4] = { 1, 0, -1, 0 };
constexpr int       dy[4] = { 0, 1, 0, -1 };

/* templates */
template<typename Container> auto sum(const Container &c) {
	using T = typename decay<decltype(*c.begin())>::type;
	return accumulate(c.begin(), c.end(), T{0});
}

template<typename Container> auto prod(const Container &c) {
	using T = typename decay<decltype(*c.begin())>::type;
	return accumulate(c.begin(), c.end(), T{0}, multiplies<>());
}

/* helper functions */
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

// mod
long long mod_add(long long a, long long b, long long m = MOD) { return (a + b) % m; }
long long mod_sub(long long a, long long b, long long m = MOD) { return (a - b + m) % m; }
long long mod_mul(long long a, long long b, long long m = MOD) { return (a * b) % m; }
long long mod_pow(long long a, long long b, long long m = MOD) {
	long long res  = 1;
	a             %= m;
	while (b) {
		if (b & 1)
			res = mod_mul(res, a, m);
		a   = mod_mul(a, a, m);
		b >>= 1;
	}
	return res;
}
long long mod_inv(long long a, long long m = MOD) { return mod_pow(a, m - 2, m); }

// clang-format on
/// }}}

/* #define HAS_TESTCASES */
/* #define PRINTCASES */

void sol() {
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
