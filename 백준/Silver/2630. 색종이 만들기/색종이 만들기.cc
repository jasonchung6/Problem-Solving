#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
int wh, bl;
vector<vector<bool>> vec(0, vector<bool>(0));

void paper(int n, int x, int y) {
	bool temp = vec[x][y], breakFlag = false;
	for (int i = x; i < x + n; ++i)
	{
		for (int j = y; j < y + n; ++j)
		{
			if (temp != vec[i][j]) {
				breakFlag = true;
				break;
			}
		}
		if (breakFlag)
			break;
	}
	if (breakFlag) {
		n = n / 2;
		paper(n, x, y);
		paper(n, x + n, y);
		paper(n, x, y + n);
		paper(n, x + n, y + n);
	}
	else {
		if (temp)
			++bl;
		else
			++wh;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, temp;
	cin >> n;
	vec.assign(n, vector<bool>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> temp;
			vec[i][j] = temp;
		}
	}

	paper(n, 0, 0);

	cout << wh << endl << bl;

	return 0;
}