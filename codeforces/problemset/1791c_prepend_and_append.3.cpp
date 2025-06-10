/*
 * Author: Saif Shahriar
 */

#include <deque>
#include <iostream>

using namespace std;

void sol() {
	int n;
	cin >> n;

	deque<char> dq(n);
	for (auto& c : dq)
		cin >> c;

	while (dq.size() && dq.front() != dq.back()) {
		dq.pop_front();
		dq.pop_back();
	}

	cout << dq.size() << '\n';
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int testcases;
	cin >> testcases;
	while (testcases--)
		sol();
}
