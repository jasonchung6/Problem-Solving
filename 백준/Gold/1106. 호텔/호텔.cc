#include <iostream>
#include <vector>
using namespace std;

constexpr int INF = 1e9;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> city(N);
    for (int i = 0; i < N; ++i) {
        cin >> city[i].first >> city[i].second;
    }

    vector<int> dp(C + 101, INF);
    dp[0] = 0;

    for (int i = 0; i <= C + 100; ++i) {
        for (int j = 0; j < N; ++j) {
            int cost = city[j].first;
            int customer = city[j].second;
            if (i >= customer) {
                dp[i] = min(dp[i], dp[i - customer] + cost);
            }
        }
    }

    int ans = INF;
    for (int i = C; i <= C + 100; ++i) {
        ans = min(ans, dp[i]);
    }

    cout << ans;
    return 0;
}