#include <iostream>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	for (int i = n; i > 0; i--)
	{
		for (int j = i; j < n; j++)
			cout << " ";
		for (int k = 0; k < i * 2 - 1; k++)
			cout << "*";
		cout << endl;
	}

	return 0;
}