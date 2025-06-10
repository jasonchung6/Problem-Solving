#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using Pii = pair<int, int>;
constexpr int INF = 1e9;

int N;
vector<vector<double>> road;
vector<vector<double>> dp;

double tsp(int cur, int visited) {
	if (visited == ((1 << N) - 1)) {
		if (road[cur][0] == 0) {
			return INF;
		}
		return road[cur][0];
	}

	double& ret = dp[cur][visited];
	if (ret != (double) - 1) {
		return ret;
	}

	ret = INF;
	for (int next = 0; next < N; ++next) {
		if (!(visited & (1 << next))) {
			ret = min(ret, tsp(next, (visited | (1 << next)))+road[cur][next]);
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	road.assign(N, vector<double>(N, 0));
	dp.assign(N, vector<double>(1 << N, -1));
	vector<Pii> city(N);

	for (int i = 0; i < N; ++i) {
		cin >> city[i].first >> city[i].second;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			if (i != j) {
				road[i][j] = sqrt(pow((city[i].first - city[j].first), 2) + pow((city[i].second - city[j].second), 2));
				road[j][i] = road[i][j];
			}
		}
	}

	cout.precision(9);
	cout << fixed;
	cout << tsp(0, 1);

	return 0;
}