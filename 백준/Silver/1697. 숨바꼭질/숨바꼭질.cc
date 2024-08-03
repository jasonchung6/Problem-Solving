#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int SIZE = 200'000;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, k2, temp;
	cin >> n >> k;

	k2 = 2 * k;
	vector<int> vec(SIZE);
	queue<int> q;
	vec[n] = 1;
	q.push(n);

	while (!vec[k])
	{
 		n = q.front();
		q.pop();
		temp = n + 1;
		if (temp <= 100000 && !vec[temp])
		{
			vec[temp] = vec[n] + 1;
			q.push(temp);
		}
		temp = n - 1;
		if (temp >= 0 && !vec[temp])
		{
			vec[temp] = vec[n] + 1;
			q.push(temp);
		}
		temp = 2 * n;
		if (temp < k2 && !vec[temp])
		{
			vec[temp] = vec[n] + 1;
			q.push(temp);
		}
	}

 	cout << vec[k] -1;

	return 0;
}