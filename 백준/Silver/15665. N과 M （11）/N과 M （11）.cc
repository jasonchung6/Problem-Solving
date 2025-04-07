#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

void backtrack(vector<int>& combination, vector<int>& numbers)
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
		if (combination.empty() && it != numbers.begin() && *it == *(it - 1))
		{
			continue;
		}
		if (check != *it)
		{
			combination.push_back(*it);
			check = *it;
			backtrack(combination, numbers);
			combination.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	vector<int> combination;
	vector<int> numbers(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> numbers[i];
	}
	sort(numbers.begin(), numbers.end());

	backtrack(combination, numbers);

	return 0;
}