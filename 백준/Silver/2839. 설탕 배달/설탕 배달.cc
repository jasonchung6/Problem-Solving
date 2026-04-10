#include<iostream>
using namespace std;

int main() {
	int N = 0;
	cin >> N;
	int N_5 = N / 5;
	int N_3 = N / 3;

	for (int i = N_5; i >= 0; i--)
	{
		for (int j = 0; j <= N_3; j++)
		{
			if (i * 5 + j * 3 == N) {
				cout << i + j;
				return 0;
			}
		}
	}
	cout << -1;

	return 0;
}