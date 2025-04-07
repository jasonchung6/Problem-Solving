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
	for (int i = 0; i < N; ++i)
	{
		if (!combination.empty() && numbers[i] < combination.back())
		{
			continue;
		}
		combination.push_back(numbers[i]);
		backtrack(combination, numbers);
		combination.pop_back();
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