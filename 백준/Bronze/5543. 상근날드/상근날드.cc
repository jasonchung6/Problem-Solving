#include<iostream>
using namespace std;

int main()
{
	int h[3] = { 0 };
	int d[2] = { 0 };
	int set = 0, drk = 2000, ham = 2000;

	for (int i = 0; i < 3; i++)
	{
		cin >> h[i];
		if (h[i] < ham)
			ham = h[i];
	}
	for (int i = 0; i < 2; i++)
	{
		cin >> d[i];
		if (d[i] < drk)
			drk = d[i];
	}
	set = drk + ham;
	cout << set - 50;

	return 0;
}