#include <iostream>
#include <vector>
using namespace std;

constexpr double MAX_SIZE = 3.0;

class Student {
public:
	string      name;
	int         roll;
	vector<int> marks = vector<int>(MAX_SIZE);

	void set(string s, int r, vector<int> m) {
		name  = s;
		roll  = r;
		marks = m;
	}

	pair<int, double> calculate() {
		int t = 0;
		for (auto& e : marks)
			t += e;
		return { t, t / MAX_SIZE };
	}

	void display() {
		cout << "Marks for " << name << " (" << roll << ")" << endl
		     << "Total: " << calculate().first << endl
		     << "Average: " << calculate().second << endl;
	}
};

int main() {
	string      name  = "Saif";
	int         roll  = 150;
	vector<int> marks = { 11, 12, 13 };

	Student s1;
	s1.set(name, roll, marks);

	Student s2;
	s2.set("Bob", 151, { 14, 15, 16 });

	s1.display();
	s2.display();
}
