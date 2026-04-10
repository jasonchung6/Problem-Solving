#include<iostream>
using namespace std;

int main() {
	int n = 0, sum = 0;
	cin >> n;
	int cow[10] = { 10,10, 10, 10, 10, 10, 10, 10, 10, 10 };
	for (int i = 0; i < n; i++)
	{
		int tempc;
		int tempn;
		cin >> tempc >> tempn;
		if (cow[tempc-1] == 10)
		{
		}
		else if (cow[tempc-1] != tempn)
		{
			sum++;
		}
		cow[tempc-1] = tempn;
	}
	cout << sum;
}