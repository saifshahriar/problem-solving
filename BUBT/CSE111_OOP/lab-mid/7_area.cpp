#include <cmath>
#include <iostream>
using namespace std;

const double PI = acos(-1);

double area(int radius) {
	return PI * radius * radius;
}

int area(int length, int width) {
	return length * width;
}

double area(double base, double height) {
	return (1 / 2.0) * base * height;
}

int main() {
	int    r = 5;
	int    l = 4, w = 6;
	double b = 3.5, h = 2.0;

	cout << "Area of circle: " << area(r) << endl;
	cout << "Area of rectangle: " << area(l, w) << endl;
	cout << "Area of triangle: " << area(b, h) << endl;
}
