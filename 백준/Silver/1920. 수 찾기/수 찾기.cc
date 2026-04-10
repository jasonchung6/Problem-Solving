#include <iostream>
//#include <vector>
#include <set>
using namespace std;

#define endl '\n'

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m,temp;
	cin >> n;
	set<int> s;
	for (int i = 0; i < n; ++i) {
		cin >> temp;
		s.insert(temp);
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> m;
		if (s.find(m) == s.end())
			cout << 0 << endl;
		else
			cout << 1 << endl;
	}

	return 0;
}