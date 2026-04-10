#include <iostream>
using namespace std;

int main() {
	int n, s, temp = 0, count = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 1; j <= s; j++)
		{
			if (s % j == 0)
				temp++;
		}
		if (temp == 2)
			count++;
		temp = 0;
	}
	cout << count;
	return 0;
}