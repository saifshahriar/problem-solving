/* Link:
 * https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
 */
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 1e5 + 5;
int           arr[MAX], que[MAX];
int           x;

bool search(int l, int r) {
	if (l > r)
		return false;

	int mid = l + (r - l) / 2;
	if (arr[mid] == x)
		return true;
	else if (x > arr[mid])
		return search(mid + 1, r);
	else
		return search(l, mid - 1);
}

int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	while (k--) {
		cin >> x;
		cout << (search(0, n - 1) ? "YES" : "NO") << '\n';
		/* cout << (binary_search(arr, arr + n, x) ? "YES" : "NO") */
		/*      << '\n';   // using STL */
	}
}
