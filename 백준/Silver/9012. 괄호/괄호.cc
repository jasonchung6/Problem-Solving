#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	bool flag;
	cin >> n;
	string str;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str.size()%2 == 1 || str[0] == ')')
		{
			cout << "NO\n";
			continue;
		}
		l = 1;
		flag = 0;
		for (int idx = 1; idx < str.size(); idx++) {
			if (str[idx] == '(')
			{
				++l;
			}
			else
			{
				--l;
			}
			if (l<0)
			{
				flag = 1;
			}
		}
		if (l == 0 && flag == 0)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}

	return 0;
}