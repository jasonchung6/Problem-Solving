#include <iostream>
using namespace std;

typedef long long ll;
constexpr ll MOD = 1e6;

struct Matrix {
	ll m[2][2];
	Matrix operator*(const Matrix& other) const {
		Matrix res = {};
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					res.m[i][j] = (res.m[i][j] + m[i][k] * other.m[k][j]) % MOD;
		return res;
	}
};

Matrix power(Matrix base, ll exp) {
	Matrix result = { {{1, 0}, {0, 1}} };
	while (exp > 0) {
		if (exp % 2 == 1)
			result = result * base;
		base = base * base;
		exp /= 2;
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	if (n == 0) {
		cout << 0 << '\n';
	}
	else {
		Matrix base = { {{1, 1}, {1, 0}} };
		Matrix result = power(base, n - 1);
		cout << result.m[0][0];
	}

	return 0;
}