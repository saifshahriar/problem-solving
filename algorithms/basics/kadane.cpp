/* kadane's algorithm
 * used is problems where you need to work with `maximum subarray sum`
 *
 * general idea: iterate and find current sum, if current sum is
 * negative, make it 0. find the maximum sum.
 */

#include <bits/stdc++.h>
using namespace std;

long long kadane(int n, vector<int>& v) {
	long long currsum = 0, maxsum = LLONG_MIN;
	for (int i = 0; i < n; ++i) {
		currsum = v[i];
		maxsum  = max(maxsum, currsum);
		if (currsum < 0)
			currsum = 0;
	}
	return maxsum;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int         n      = 8;
	vector<int> v      = { -1, 3, -2, 5, 3, -5, 2, 2 };
	long long   maxsum = kadane(n, v);
	cout << maxsum << '\n';
}
