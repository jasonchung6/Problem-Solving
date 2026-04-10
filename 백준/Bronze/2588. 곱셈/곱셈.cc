#include <iostream>
using namespace std;

int main() {
	int a = 0, b = 0;
	cin >> a >> b;

	int c = 0;
	c = b % 10;
	cout << a * c << endl;
	c = b / 10;
	c = c % 10;
	cout << a * c << endl;
	c = b / 100;
	cout << a * c << endl;
	cout << a * b << endl;

	return 0;
}