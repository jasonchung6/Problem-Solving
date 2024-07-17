#include <iostream>
#include <vector>
#include <queue>
//#include <set>
//#include <algorithm>
//#include <cmath>
//#include <string>
using namespace std;

constexpr int SIZE = 50;
vector<vector<bool>> vec;
vector<vector<bool>> visited;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n, m;

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		pair<int, int> node = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = node.first + dx[i];
			int ny = node.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (!visited[nx][ny] && vec[nx][ny])
			{
				q.push({ nx,ny });
				visited[nx][ny] = 1;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t, k, x, y, jilung;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		jilung = 0;
		cin >> m >> n >> k;
		vec.assign(n, vector<bool>(m, 0));
		visited.assign(n, vector<bool>(m, 0));
		for (int j = 0; j < k; ++j)
		{
			cin >> x >> y;
			vec[y][x] = 1;
		}
		x = 1;
		for (int j = 0; j < n; ++j) //y축
		{
			for (int k = 0; k < m; ++k) //x축
			{
				if (vec[j][k] && !(visited[j][k]))
				{
					++jilung;
					bfs(j, k);
				}
			}
		}
		cout << jilung << "\n";
	}

	return 0;
}