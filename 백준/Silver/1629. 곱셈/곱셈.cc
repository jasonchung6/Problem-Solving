#include <iostream>
using namespace std;

long long A, B, C;

long long solve(long long b1)
{
	if (b1 == 1)
	{
		return A % C;
	}

	long long b2 = b1 / 2;
	if (b1 % 2 == 1)
	{
		return (solve(b2) * solve(b2 + 1)) % C;
	}
	else
	{
		long long a2 = solve(b2);
		return (a2 * a2) % C;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> C;
	cout << solve(B);

	return 0;
}