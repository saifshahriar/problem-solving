#include<iostream>

using namespace std;

int main() {
	int n; cin>>n;
	string index[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	string res = (n <= 9) ? index[n-1] : "Greater than 9";
	cout<<res<<endl;
	return 0;
}