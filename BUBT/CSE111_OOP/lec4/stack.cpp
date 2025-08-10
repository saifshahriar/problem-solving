#include <cstdio>
#include <iostream>
using namespace std;

template <typename T> class Stack {
	int size;
	T*  st;
	int lidx;

public:
	Stack(int sz) : size(sz), lidx(0) {
		st = new T[size];
	}

	~Stack() {
		delete[] st;
	}

	void push(T e) {
		if (lidx == size) {
			cout << "Stack is full!" << endl;
			return;
		}
		st[lidx] = e;
		lidx++;
	}

	T pop() {
		if (lidx == 0) {
			cout << "Stack is empty!" << endl;
			return -1;
		}
		lidx--;
		return st[lidx];
	}

	T* begin() {
		return st;
	}

	T* end() {
		return st + lidx;
	}
};

int main() {
	Stack<int> st(10);
	st.push(5);
	st.push(9);
	st.push(12);

	cout << "Before popping:" << endl;
	for (auto& e : st)
		cout << e << ' ';
	cout << endl;

	st.pop();

	cout << "After popping:" << endl;
	for (auto& e : st)
		cout << e << ' ';
	cout << endl;

	/* Stack<char> c(5); */
	/* c.push('a'); */
	/* printf("%c", *c.begin()); */
}
