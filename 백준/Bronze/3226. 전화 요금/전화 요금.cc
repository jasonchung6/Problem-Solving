#include<iostream>
using namespace std;

int main() {
	int n, h, m, d, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d:%d %d", &h, &m, &d);
		if (h > 6 && h < 19)
		{
			if (h == 18 && m + d > 59)
			{
				sum += (60 - m) * 10;
				sum += (d - (60 - m)) * 5;
			}
			else
			{
				sum += d * 10;
			}
		}
		else
		{
			if (h == 6 && m + d > 59)
			{
				sum += (60 - m) * 5;
				sum += (d - (60 - m)) * 10;
			}
			else
			{
				sum += d * 5;
			}
		}
	}
	cout << sum;
}