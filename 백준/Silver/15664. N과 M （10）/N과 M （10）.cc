#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

void backtrack(vector<int>& combination, vector<pair<int, int>>& numbers)
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
	int check = 0;
	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		if ((*it).second == 0 && check != (*it).first)
		{
			if (!combination.empty() && (*it).first < combination.back())
			{
				continue;
			}
			combination.push_back((*it).first);
			(*it).second = 1;
			check = (*it).first;
			backtrack(combination, numbers);
			combination.pop_back();
			(*it).second = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<int> combination;
	vector<pair<int, int>> numbers(N, { 0, 0 });
	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i].first;
	}
	sort(numbers.begin(), numbers.end());

	backtrack(combination, numbers);

	return 0;
}