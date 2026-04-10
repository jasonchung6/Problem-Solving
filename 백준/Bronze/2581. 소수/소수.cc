#include <iostream>
using namespace std;

int main() {
	int m, n, temp = 0, count = 0, sml = -1;
	cin >> m >> n;
	for (int i = m; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				temp++;
		}
		if (temp == 2)
		{
			count += i;
			if (sml == -1)
				sml = i;
		}
		temp = 0;
	}
	if (count != 0)
		cout << count << endl;
	cout << sml;
	return 0;
}