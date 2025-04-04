#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int N, M;

void backtrack(int dis, vector<int>& combination, vector<pair<int, int>>& numbers)
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

	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		if ((*it).second == 0)
		{
			combination.push_back((*it).first);
			(*it).second = 1;
			backtrack(distance(numbers.begin(), it + 1), combination, numbers);
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

	backtrack(0, combination, numbers);

	return 0;
}