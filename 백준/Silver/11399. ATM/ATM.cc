#include <iostream>
#include <set>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, temp, ans = 0;
	cin >> n;
	multiset<int> ms;

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		ms.insert(temp);
	}
	temp = 0;
	for (const int& elem : ms) {
		ans += elem * (n - temp++);
	}
	cout << ans;

	return 0;
}