#include <iostream>
#include <algorithm>
using namespace std;

int x[1000001];

int main() {
	int n;
	cin >> n;
	x[1] = 0;
	x[2] = 1;
	x[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		x[i] = x[i - 1] + 1;
		if (i % 2 == 0)
			x[i] = min(x[i], x[i / 2] + 1);
		if (i % 3 == 0)
			x[i] = min(x[i], x[i / 3] + 1);
	}
	cout << x[n];
	return 0;
}