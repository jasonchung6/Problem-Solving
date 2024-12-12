#include <iostream>
#include <map>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, temp;
	map<int, int> mp;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		cin >> temp;
		++mp[temp];
	}

	cin >> m;
	for (size_t j = 0; j < m; j++)
	{
		cin >> temp;
		cout << mp[temp] << " ";
	}


	return 0;
}