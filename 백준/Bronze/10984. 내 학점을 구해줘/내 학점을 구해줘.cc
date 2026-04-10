#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	int* tc = new int[t];
	float* tg = new float[t];
	for (int t1 = 0; t1 < t; t1++)
	{
		cin >> n;
		int* nc = new int[n];
		float* ng = new float[n];
		float temp, temp_g = 0;
		tc[t1] = 0;
		for (int n1 = 0; n1 < n; n1++)
		{
			cin >> nc[n1] >> ng[n1];
			tc[t1] += nc[n1];
			temp = (float)nc[n1] * ng[n1];
			temp_g += temp;
		}
		tg[t1] = temp_g / (float)tc[t1];
		delete[] nc, ng;
	}
	cout.precision(2);
	for (int t1 = 0; t1 < t; t1++)
		cout << tc[t1] << " " << tg[t1] << endl;
	return 0;
}