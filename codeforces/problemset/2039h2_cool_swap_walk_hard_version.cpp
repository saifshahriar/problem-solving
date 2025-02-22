#include <bits/stdc++.h>
using namespace std;
typedef double             db;
typedef long long          ll;
typedef unsigned long long ull;
const int                  N = 2010;
int                        T, n, tot;
int                        a[N];
vector<int>                X[N], Y[N];

void path1(int num)   //(1,1)->(1,2)->(2,2)->(2,3)->(3,3)->...
{
	for (int i = 1; i <= n; i++) {
		X[num].push_back(i), Y[num].push_back(i);
		if (i != n) {
			X[num].push_back(i), Y[num].push_back(i + 1);
			swap(a[i], a[i + 1]);
		}
	}
}

void path2(int num)   //(1,1)->(1,n)->(n,n)
{
	for (int i = 1; i <= n; i++) {
		X[num].push_back(1), Y[num].push_back(i);
		swap(a[1], a[i]);
	}
	for (int i = 2; i <= n; i++) {
		X[num].push_back(i), Y[num].push_back(n);
		swap(a[i], a[n]);
	}
}

void path3(int num, vector<int> p)   // swap(1,p[0]),(2,p[1]),... note p[0]!=1
{
	for (int i = 1; i <= p[0]; i++) {
		X[num].push_back(1), Y[num].push_back(i);
		swap(a[1], a[i]);
	}
	for (int i = 1; i < p.size(); i++) {
		for (int j = p[i - 1]; j <= p[i]; j++) {
			X[num].push_back(i + 1), Y[num].push_back(j);
			swap(a[i + 1], a[j]);
		}
	}
	int x = p.size(), y = p.back();
	while (x != n) {
		x++;
		X[num].push_back(x), Y[num].push_back(y);
		swap(a[x], a[y]);
	}
	while (y != n) {
		y++;
		X[num].push_back(x), Y[num].push_back(y);
		swap(a[x], a[y]);
	}
}

void walk1(int j) {
	X[tot].push_back(j - 1), Y[tot].push_back(j);
	X[tot].push_back(j - 1), Y[tot].push_back(j + 1);
	X[tot].push_back(j), Y[tot].push_back(j + 1);
	X[tot].push_back(j + 1), Y[tot].push_back(j + 1);
	swap(a[j - 1], a[j + 1]);
}

void walk2(int j) {
	X[tot].push_back(j - 1), Y[tot].push_back(j);
	X[tot].push_back(j), Y[tot].push_back(j);
	X[tot].push_back(j), Y[tot].push_back(j + 1);
	X[tot].push_back(j + 1), Y[tot].push_back(j + 1);
	swap(a[j - 1], a[j]);
	swap(a[j], a[j + 1]);
}

void walk3(int j) {
	X[tot].push_back(j - 1), Y[tot].push_back(j);
	X[tot].push_back(j), Y[tot].push_back(j);
	swap(a[j - 1], a[j]);
}

void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	tot = 0;
	for (int i = 1; i <= 3 * n; i++)
		X[i].clear(), Y[i].clear();
	vector<pair<int, int> > pr;
	for (int i = 1; i <= n; i++)
		pr.push_back(make_pair(a[i], i));
	sort(pr.begin(), pr.end());
	for (int i = 1; i <= n; i++)
		a[pr[i - 1].second] = i;
}

void step1() {
	int         p1, pn;
	vector<int> p;
	for (int i = 1; i <= n; i++)
		if (a[i] == 1)
			p1 = i;
	if (p1 != 1) {
		p.push_back(p1);
		path3(++tot, p);
	}
	if (n == 2)
		return;
	tot++;
	X[tot].push_back(1), Y[tot].push_back(1);
	for (int j = 2; j <= n; j += 2)
		if (j + 1 > n)
			walk3(j);
		else if (a[j] == n)
			walk1(j);
		else
			walk2(j);
	p1 = n;
	for (int i = 1; i <= n; i++)
		if (a[i] == n)
			pn = i;
	p.clear();
	p.push_back(pn);
	p.push_back(p1);
	path3(++tot, p);
	p.clear();
	for (int i = 1; i <= n; i++)
		if (a[i] <= (n + 1) / 2)
			p.push_back(i);
	path3(++tot, p);
}

void step2() {
	int head;
	if (n & 1) {
		for (int t = 1; t <= 2; t++) {
			head = n / 2 + 2;
			for (int i = 1; i <= n / 2 + (t == 1); i++) {
				tot++;
				X[tot].push_back(1), Y[tot].push_back(1);
				for (int j = 2; j <= n; j++)
					if (!(head <= j && j <= head + n / 2 - 1))
						walk3(j);
					else if (j == head && (head & 1))
						walk3(j);
					else if (!(head <= j + 1 && j + 1 <= head + n / 2 - 1))
						walk3(j);
					else if (a[j] > a[j + 1])
						walk1(j), j++;
					else
						walk2(j), j++;
				head--;
			}
		}
	} else {
		for (int t = 1; t <= 2; t++) {
			head = n / 2 + 1;
			for (int i = 1; i <= n / 2; i++) {
				tot++;
				X[tot].push_back(1), Y[tot].push_back(1);
				for (int j = 2; j <= n; j++)
					if (!(head <= j && j <= head + n / 2 - 1))
						walk3(j);
					else if (j == head && (head & 1))
						walk3(j);
					else if (!(head <= j + 1 && j + 1 <= head + n / 2 - 1))
						walk3(j);
					else if (a[j] > a[j + 1])
						walk1(j), j++;
					else
						walk2(j), j++;
				head--;
			}
		}
	}
}

void output() {
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) {
		for (int j = 1; j < 2 * n - 1; j++)
			if (X[i][j] == X[i][j - 1])
				printf("R");
			else
				printf("D");
		printf("\n");
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		init();
		step1();
		step2();
		output();
	}

	return 0;
}
