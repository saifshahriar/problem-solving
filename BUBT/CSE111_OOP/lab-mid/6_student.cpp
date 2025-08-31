#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 10;

class Student {
public:
	string name;
	string id;
	int    mark;
	int    dmark;

	Student(string n = "", string i = "", int m = 0, int d = 0) :
	    name(n), id(i), mark(m), dmark(d) {
	}

	void input() {
		cout << "Enter student info [name id mark] ";
		cin >> name >> id >> mark;
	}

	void display() {
		if (mark > dmark) {
			cout << "Name: " << name << endl
			     << "ID:   " << id << endl
			     << "Mark: " << mark << endl;
		}
	}
};

int main() {
	int dmark;
	cout << "Enter a desired mark: ";
	cin >> dmark;

	Student s[MAX_SIZE];
	int     sum = 0;
	for (int i = 0; i < MAX_SIZE; ++i) {
		s[i].input();
		s[i].dmark  = dmark;
		sum        += s[i].mark;
	}

	for (int i = 0; i < MAX_SIZE; ++i)
		s[i].display();
	cout << "Avg mark: " << sum / MAX_SIZE << endl;
}
