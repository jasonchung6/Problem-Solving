#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using Pii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	long long ANS = 0;
	cin >> N >> K;
	vector<Pii> juwel(N);
	vector<int> bag(K);
	priority_queue<int> pq;
	for (int i = 0; i < N; ++i) {
		int m, v;
		cin >> m >> v;
		juwel[i] = { m,v };
	}
	for (int i = 0; i < K; ++i) {
		cin >> bag[i];
	}

	sort(bag.begin(), bag.end());
	sort(juwel.begin(), juwel.end());


	int jewel_idx = 0;
	for (const auto& w : bag) {
		while (jewel_idx < N && juwel[jewel_idx].first <= w) {
			pq.push(juwel[jewel_idx].second);
			jewel_idx++;
		}

		if (!pq.empty()) {
			ANS += pq.top();
			pq.pop();
		}
	}

	cout << ANS;

	return 0;
}