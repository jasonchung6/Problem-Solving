#include <iostream>
#include <cmath>
using namespace std;

constexpr int SIZE = 246913;
bool primeArr[SIZE] = { 0, };
int N = 0, ANS = 0;

bool isPrime(int n)
{
    int sqrtN = (int)sqrt(n);
	for (int i = 2; i <= sqrtN; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
    return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i <= SIZE; ++i)
	{
		if (isPrime(i))
		{
			primeArr[i + 1] = 1;
		}
	}

	int N, ANS;
	while (1)
	{
		ANS = 0;
		cin >> N;
		if (N == 0)
		{
			return 0;
		}

		for (int i = N+1; i <= 2 * N; i++)
		{
			if (primeArr[i + 1])
			{
				++ANS;
			}
		}
		cout << ANS << '\n';
	}
	return 0;
}