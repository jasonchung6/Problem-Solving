#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    bool ans = 0;
    int sqrtN = (int)sqrt(n);
    for (int i = 2; i <= sqrtN; i++)
        if (n % i == 0)
            ans = true;
    return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	if (N == 1)
	{
		++N;
	}
	for (int i = N; i <= M; i++)
	{
		if (!isPrime(i))
		{
			cout << i << '\n';
		}
	}

	return 0;
}