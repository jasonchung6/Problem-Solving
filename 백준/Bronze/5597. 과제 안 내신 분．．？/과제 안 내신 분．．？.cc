#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
constexpr int SIZE = 30;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	vector<bool> vec(30, 0);
	int n;
	for (int i = 0; i < 28; ++i)
	{
		cin >> n;
		vec[n - 1] = 1;
	}

	for (int i = 0; i < 30; ++i)
		if (!vec[i])
			cout << i + 1 << endl;

	return 0;
}