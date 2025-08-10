#include <iostream>
#include <ostream>
using namespace std;

typedef struct {
	string name;
	int    age;
	float  gpa;
	char   grade;
} Student;

ostream& operator<<(ostream& os, const Student& s) {
	return os << "Name: " << s.name << endl
	          << "Age: " << s.age << endl
	          << "GPA: " << s.gpa << endl
	          << "Grade: " << s.grade << endl;
}

int main() {
	Student* student1 = new Student;
	student1->name    = "Saif Shahriar";
	student1->age     = 21;
	student1->gpa     = 3.69;
	student1->grade   = 'A';
	cout << student1 << endl;
	delete student1;
}
