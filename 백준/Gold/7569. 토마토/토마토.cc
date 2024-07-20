#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

//constexpr int SIZE = 101;
vector<vector<vector<int>>> vec;
vector<vector<vector<bool>>> visited;
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };
int n, m, h;

struct myType {
	int x, y, z;
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int x, y, z, nx, ny, nz, temp, ans = 0, remain = 0;
	cin >> m >> n >> h;
	vec.assign(h, vector<vector<int>>(n, vector<int>(m, 0)));
	visited.assign(h, vector<vector<bool>>(n, vector<bool>(m, 0)));
	queue<myType> nextVisit;
	queue<myType> visit;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				cin >> temp;
				vec[i][j][k] = temp;
				if (temp == 0)
					++remain;
				else if (temp == 1)
					nextVisit.push({ j,k,i });
			}
		}
	}
	while (!nextVisit.empty()) {
		while (!nextVisit.empty()) {
			x = nextVisit.front().x;
			y = nextVisit.front().y;
			z = nextVisit.front().z;
			nextVisit.pop();
			if (!(visited[z][x][y]))
			{
				for (int i = 0; i < 6; ++i) {
					nx = x + dx[i];
					ny = y + dy[i];
					nz = z + dz[i];
					if (nx < 0 || ny < 0 || nz < 0 || nx >= n || ny >= m || nz >= h || vec[nz][nx][ny] != 0)
						continue;
					if (!visited[nz][nx][ny])
					{
						vec[nz][nx][ny] = 1;
						visit.push({ nx,ny,nz });
						--remain;
					}
				}
			}
			visited[z][x][y] = 1;
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