#include <iostream>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t, a, b;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}

	return 0;
}