#include<iostream>
using namespace std;

int main()
{
	long i = 1;
	long n0 = 1, n1 = 1, n = 0;
	cin >> n;

	for (int j = 2; j < n; j++)
	{
		i = n0 + n1;
		n0 = n1;
		n1 = i;
	}

	cout << i;

	return 0;
}