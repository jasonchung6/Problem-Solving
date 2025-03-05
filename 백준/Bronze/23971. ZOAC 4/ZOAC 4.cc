#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	int H, W, N, M;
	int H1, W1, N1, M1;
	int ANS = 0;

	cin >> H >> W >> N >> M;

	N1 = N + 1;
	M1 = M + 1;

	H1 = H / N1;
	W1 = W / M1;

	if (H % N1 != 0)
	{
		++H1;
		H1 = N1 * H1;
		H1 /= N1;
	}

	if (W % M1 != 0)
	{
		++W1;
		W1 = M1 * W1;
		W1 /= M1;
	}
	cout << H1 * W1;

	return 0;
}