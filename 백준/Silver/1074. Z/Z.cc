#include <iostream>
using namespace std;

int ans = 0;

int z(int nPow, int r, int c) {
	if (nPow == 1) {
		if (r == 1)
			++ans;
		if (c == 1)
			++ans;
		if (r == 1 && c == 1)
			++ans;
		return ans;
	}
	nPow /= 2;

	if (r < nPow) {
		if (c < nPow)
			return z(nPow, r, c);
		else {
			ans += nPow * nPow;
			return z(nPow, r, c - nPow);
		}
	}
	else{
		if (c < nPow) {
			ans += nPow * nPow * 2;
			return z(nPow, r - nPow, c);
		}
		else {
			ans += nPow * nPow * 3;
			return z(nPow, r - nPow, c - nPow);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, r, c;
	cin >> n >> r >> c;

	cout << z((1 << n), r, c);

	return 0;
}