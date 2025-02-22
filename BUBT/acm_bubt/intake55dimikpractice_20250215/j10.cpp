/*
 * Author: Saif Shahriar
 */

#define InTheNameofAllah ios::sync_with_stdio(0), cin.tie(0);
#include <bits/stdc++.h>
using namespace std;
#define HAS_TESTCASES

void sol() {
	int r1, r2, b;
	cin >> r1 >> r2 >> b;
	double ball_baki = 300 - b;
	double run_rate  = r2 / (ball_baki / 6.0);
	double req_rate  = (r1 - r2 + 1) / (b / 6.0);
	if (r2 > r1)
		req_rate = 0;
	printf("%0.2lf %0.2lf\n", run_rate, req_rate);
}

int32_t main() {
	InTheNameofAllah
	int testcases = 1;
	// clang-format off
	#ifdef HAS_TESTCASES
	cin >> testcases;
	#endif
	for (int i = 1; i <= testcases; ++i)
		sol();

}
