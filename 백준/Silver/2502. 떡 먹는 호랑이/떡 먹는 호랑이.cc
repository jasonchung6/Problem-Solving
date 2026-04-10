#include<iostream>
using namespace std;

int fibo(int, int, int);

int main() {
	int D = 0, K = 0, K1 = 0, K2 = 0;
	cin >> D >> K;

	for (int i = 1; i < K; i++)
	{
		for (int j = 1;j < K; j++)
		{
			if (fibo(i, j, D)==K)
			{
				cout << i << endl << j;
				return 0;
			}
		}
	}

	return 0;
}

int fibo(int a, int b, int d) {
	int f = 1;
	int n0 = a, n1 = b;

	for (int i = 2; i < d; i++)
	{
		f = n0 + n1;
		n0 = n1;
		n1 = f;
	}

	return f;
}