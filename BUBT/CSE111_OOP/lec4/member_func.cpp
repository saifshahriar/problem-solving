#include <iostream>

using namespace std;

class Box {
public:
	int length, width, height;

	void display_vol();
};

void Box::display_vol() {
	cout << "Volume of the box is: " << length * width * height << endl;
}

int main() {
	int l = 1, w = 2, h = 3;

	Box* b1    = new Box;
	b1->length = l;
	b1->width  = w;
	b1->height = h;

	b1->display_vol();
	delete b1;
}
