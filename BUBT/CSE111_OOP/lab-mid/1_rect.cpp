#include <iostream>
using namespace std;

class Rectangle {
private:
	int length;
	int width;

public:
	Rectangle(int l = 0, int w = 0) : length(l), width(w) {
	}

	void set(int l, int w) {
		length = l;
		width  = w;
	}

	int calculate_area() {
		return length * width;
	}

	int calculate_perimeter() {
		return 2 * (length + width);
	}

	void display() {
		cout << "Area: " << calculate_area() << endl
		     << "Perimeter: " << calculate_perimeter() << endl;
	}
};

int main() {
	Rectangle r1(2, 3), r2;
	r2.set(5, 6);

	r1.display();
	r2.display();
}
