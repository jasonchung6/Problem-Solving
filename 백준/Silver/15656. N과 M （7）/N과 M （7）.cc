#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

void backtrack(int dis, vector<int>& combination, vector<int>& numbers)
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
		combination.push_back(numbers[i]);
		backtrack(i + 1, combination, numbers);
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

	backtrack(0, combination, numbers);

	return 0;
}