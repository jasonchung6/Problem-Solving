#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

using State = tuple<int, int, int, int>;
int M, N, ANS = 1e9;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
queue<State> q; //x y wall dist
vector<vector<bool>> grid;
vector<vector<bool>> visited;
vector<vector<bool>> visited2;

void bfs() {
	while (!q.empty()) {
		auto [vx, vy, wall, dist] = q.front();
		++dist;
		if (vx == M && vy == N) {
			ANS = min(ANS, dist);
		}
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = vx + dx[i];
			int ny = vy + dy[i];

			if (wall == 0 && visited2[nx][ny] == 1) {
				continue;
			}
			else if (wall == 1 && visited[nx][ny] == 1) {
				continue;
			}

			if (nx < 1 || nx > M || ny < 1 || ny > N) {
				continue;
			}

			if (grid[nx][ny] == 1) {
				if (wall == 0) {
					q.push({ nx,ny,1,dist });
					visited[nx][ny] = 1;
				}
				else {
					continue;
				}
			}
			else {
				q.push({ nx,ny,wall,dist });
				if (wall == 0) {
					visited2[nx][ny] = 1;
					visited[nx][ny] = 1;
				}
				else {
					//visited2[nx][ny] = 1;
					visited[nx][ny] = 1;
				}
			}
		}
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;

	grid.assign(M + 1, vector<bool>(N + 1, 0));
	visited.assign(M + 2, vector<bool>(N + 2, 0));
	visited2.assign(M + 2, vector<bool>(N + 2, 0));

	for (int i = 1; i <= M; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < N; ++j) {
			if (temp[j] == '1') {
				grid[i][j + 1] = 1;
			}
		}
	}

	q.push({ 1,1,0,0 });
	bfs();
	if (ANS == 1e9) {
		cout << -1;
	}
	else {
		cout << ANS;
	}

	return 0;
 
}