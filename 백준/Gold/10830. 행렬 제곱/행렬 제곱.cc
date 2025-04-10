#include <iostream>
#include <vector>
using namespace std;

int N;
long long B;
vector<vector<int>> A;
vector<vector<int>> ANS;

vector<vector<int>> matrixMul(const vector<vector<int>> &a, const vector<vector<int>> &b)
{
	vector<vector<int>> equal(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int sum = 0;
			for (int k = 0; k < N; ++k)
			{
				sum += a[i][k] * b[k][j];
			}
			if (sum >= 1000)
			{
				sum %= 1000;
			}
			equal[i][j] = sum;
		}
	}
	ANS = equal;
	return ANS;
}

vector<vector<int>> recursive(long long b)
{
	if (b == 1)
	{
		return A;
	}

	if (b % 2 == 1)
	{
		return matrixMul(A, recursive(b - 1));
	}
	else
	{
		vector<vector<int>> temp = recursive(b / 2);
		ANS = matrixMul(temp, temp);
		return ANS;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> B;
	A.assign(N, vector<int>(N, 0));
	ANS.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> A[i][j];
			if (A[i][j] >= 1000)
			{
				A[i][j] %= 1000;
			}
		}
	}
	ANS = A;

	recursive(B);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{	
	 		cout << ANS[i][j] << " ";
	 	}
		cout << "\n";
	 }

	return 0;
}