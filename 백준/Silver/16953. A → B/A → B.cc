#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, ans = 1, errFlag = 0;
	cin >> a >> b;

	if (b % 2 == 1)
	{
		if (b%10 != 1)
		{
			errFlag = 1;
		}
	}

	while (!errFlag)
	{
		if (a == b)
		{
			break;
		}
		else if (a > b)
		{
			errFlag = 1;
		}
		else if (b % 10 == 1)
		{
			--b;
			b /= 10;
		}
		else if (b % 2 == 0)
		{
			b /= 2;
		}
		else
		{
			errFlag = 1;
		}
		++ans;
	}

	if (errFlag == 0)
	{
		cout << ans;
	}
	else
	{
		cout << -1;
	}

	return 0;
}