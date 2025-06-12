#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--) {
		int N, K, W;
		cin >> N >> K;
        vector<int> D(N + 1);
        vector<int> indegree(N + 1, 0);
        vector<vector<int>> graph(N + 1);
        for (int i = 1; i <= N; ++i) {
            cin >> D[i];
        }
        for (int i = 0; i < K; ++i) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            indegree[y]++;
        }
        cin >> W;

        vector<int> dp(N + 1, -1);
        queue<int> q;
        for (int i = 1; i <= N; ++i) {
            if (indegree[i] == 0) {
                dp[i] = D[i];
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : graph[cur]) {
                dp[next] = max(dp[next], dp[cur] + D[next]);
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        cout << dp[W] << '\n';
    }

    return 0;
}
