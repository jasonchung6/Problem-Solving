#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, temp1, temp2, ans;
	cin >> n >> m;

	vector<int> vec;
	vec.push_back(0);

	for (int i = 0; i < n; ++i)
	{
		cin >> temp1;
		vec.push_back(temp1+vec[i]);
	}		

	while (m--) {
		cin >> temp1 >> temp2;
		cout << vec[temp2] - vec[temp1-1] << endl;
	}

	return 0;
}