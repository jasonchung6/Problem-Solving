#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//constexpr int SIZE = 1001;
vector<vector<int>> vec;
vector<vector<bool>> visited;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x, y, nx, ny, temp, ans = 0, remain = 0;
	cin >> m >> n;
	vec.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<bool>(m, 0));
	queue<pair<int, int>> nextVisit;
	queue<pair<int, int>> visit;
	for (int j = 0; j < n; ++j)
	{
		for (int k = 0; k < m; ++k)
		{
			cin >> temp;
			vec[j][k] = temp;
			if (temp == 0)
				++remain;
			else if (temp == 1)
				nextVisit.push({ j,k });
		}
	}
	while (!nextVisit.empty()){
		while (!nextVisit.empty()) {
			x = nextVisit.front().first;
			y = nextVisit.front().second;
			nextVisit.pop();
			if (!(visited[x][y]))
			{
				for (int i = 0; i < 4; ++i) {
					nx = x + dx[i];
					ny = y + dy[i];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m || vec[nx][ny] != 0)
						continue;
					if (!visited[nx][ny])
					{
						vec[nx][ny] = 1;
						visit.push({ nx,ny });
						--remain;
					}
				}
			}
			visited[x][y] = 1;
		}
		nextVisit = visit;
		while (!visit.empty())
			visit.pop();
		ans++;
	}
	if (remain != 0)
		cout << -1;
	else
		cout << --ans;

	return 0;
}