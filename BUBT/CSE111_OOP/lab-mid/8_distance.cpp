#include <iostream>
using namespace std;

class Distance {
public:
	int ft;
	int in;
};

Distance add_distance(Distance d1, Distance d2) {
	Distance d;
	d.in  = d1.ft * 12 + d1.in + d2.ft * 12 + d2.in;
	d.ft  = d.in / 12;
	d.in %= 12;
	return d;
}

int main() {
	Distance d1 { 5, 8 };
	Distance d2 { 3, 11 };
	cout << add_distance(d1, d2).ft << "ft " << add_distance(d1, d2).in
	     << "in" << endl;
}
