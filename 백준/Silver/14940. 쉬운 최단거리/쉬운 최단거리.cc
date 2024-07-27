#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

vector<vector<int>> vec;
vector<vector<bool>> visited;
queue<pair<int, int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;

void bfs(int x, int y)
{
    int xx, yy;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty())
    {
        pair<int, int> xy = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            xx = xy.first + dx[i];
            yy = xy.second + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            else if (vec[xx][yy] == 0)
            {
                visited[xx][yy] = true;
                continue;
            }
            if (!visited[xx][yy])
            {
                visited[xx][yy] = true;
                q.push({xx, yy});
                vec[xx][yy] = vec[xy.first][xy.second] + 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> n >> m;
    vec.assign(n, vector<int>(m));
    visited.assign(n, vector<bool>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> vec[i][j];
            if (vec[i][j] == 2)
            {
                x = i;
                y = j;
            }
        }
    }

    vec[x][y] = 0;
    bfs(x, y);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!visited[i][j] && vec[i][j] != 0)
                vec[i][j] = -1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << vec[i][j] << " ";
        cout << endl;
    }

    return 0;
}