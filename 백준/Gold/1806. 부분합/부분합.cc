#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, S;
	cin >> N >> S;
	vector<int> sequence(N + 1);

	for (int i = 0; i < N; ++i)
	{
		cin >> sequence[i];
	}

	int sum = 0, length = 0;
	int ANS = N + 1;

	for (int i = 0; i < N; ++i)
	{
		sum += sequence[i];
		++length;
		if (sum >= S)
		{
			while (sum >= S)
			{
				ANS = min(ANS, length);
				sum -= sequence[i - length + 1];
				--length;
			}
		}
	}

	if (ANS == N + 1)
	{
		ANS = 0;
	}
	cout << ANS;

	return 0;
}