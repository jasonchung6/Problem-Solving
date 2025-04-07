#include <iostream>
#include <vector>
using namespace std;

int N, M;

void backtrack(vector<int>& combination)
{
	if (combination.size() == M)
	{
		for (const int& num : combination)
		{
			cout << num << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (!combination.empty() && i < combination.back())
		{
			continue;
		}
		combination.push_back(i);
		backtrack(combination);
		combination.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<int> combination;
	backtrack(combination);

	return 0;
}