#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
//constexpr int SIZE = 11;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	vector<int> vec(11);
	vec[0] = 1;
	vec[1] = 2;
	vec[2] = 4;
	for (int i = 3; i < 11; ++i)
		vec[i] = vec[i - 3] + vec[i - 2] + vec[i - 1];

	int n, temp;
	cin >> n;

	while (n--) {
		cin >> temp;
		cout << vec[temp-1] << endl;;
	}

	return 0;
}