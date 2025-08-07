#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	int bid = 0;
	cin >> N >> K;
	vector<Pii> price(N);
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(0);
	for (int i = 0; i < N; ++i)
	{
		cin >> price[i].first >> price[i].second;
		if (price[i].first >= price[i].second)
		{
			++bid;
		}
		else
		{
			pq.push(price[i].second - price[i].first);
		}
	}

	for (int i = 0; i < K - bid; ++i)
	{
		pq.pop();
	}

	cout << pq.top();

	return 0;
}