#include<iostream>
using namespace std;

int main() {
	int n, m, a[10000];
	cin >> n >> m;
	a[0] = 1;
	for (int i = 1; i <= n; ++i) {
		a[i] = a[i - 1];
		if (i - m >= 0) a[i] = (a[i] + a[i - m]) % 1000000007;
	}
	cout << a[n];
}