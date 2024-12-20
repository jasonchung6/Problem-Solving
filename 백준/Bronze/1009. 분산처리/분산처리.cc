#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, A, B, ANS;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		ANS = A;
		for (int j = 1; j < B; j++)
		{
			ANS %= 10;
			ANS *= A;
		}
		ANS %= 10;
		if (ANS == 0)
		{
			ANS = 10;
		}
		cout << ANS << "\n";
	}

	return 0;
}