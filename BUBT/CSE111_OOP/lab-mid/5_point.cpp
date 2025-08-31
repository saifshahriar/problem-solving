#include <iostream>
using namespace std;

class Point {
private:
	int x, y;

public:
	Point(int nx = 0, int ny = 0) : x(nx), y(ny) {
	}

	Point(const Point& p) : x(p.x), y(p.y) {
	}

	int getx() {
		return x;
	}

	int gety() {
		return y;
	}

	void display() {
		cout << "X = " << getx() << endl << "Y = " << gety() << endl;
	}
};

int main() {
	Point p1(10, 20);
	p1.display();

	Point p2(p1);
	p2.display();
}
