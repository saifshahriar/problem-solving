#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 1000; i >= 1; i--)
		cout << i << ((i % 5 == 1) ? "\n" : " ");
	return 0;
}
