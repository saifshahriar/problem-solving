#include <cmath>
#include <iostream>
using namespace std;

const double PI = acos(-1);

class Circle {
private:
	int radius;

public:
	void set(int r) {
		radius = r;
	}

	pair<double, double> calculate() {
		return { PI * radius * radius, 2 * PI * radius };
	}

	void display() {
		cout << "Area: " << calculate().first << endl
		     << "Circum: " << calculate().second << endl;
	}
};

int main() {
	Circle c;
	c.set(12);
	c.display();
}
