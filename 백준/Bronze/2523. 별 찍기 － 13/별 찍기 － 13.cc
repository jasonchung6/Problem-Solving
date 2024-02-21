#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = 0; k < i + 1; k++)
			cout << "*";
		cout << endl;
	}
	for (int i = n; i > 0; i--)
	{
		for (int k = 0; k < i; k++)
			cout << "*";
		cout << endl;
	}

	return 0;
}