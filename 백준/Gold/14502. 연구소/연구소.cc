#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Pii = pair<int, int>;
constexpr int SIZE = 10;
vector<vector<int>> map_origin(SIZE, vector<int>(SIZE, 0));
vector<vector<int>> map_temp(SIZE, vector<int>(SIZE, 0));
vector<Pii> virus;

int N, M;
int ANS = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
Pii wall[3];

void check_area()
{
    int safe_area = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map_temp[i][j] == 0)
            {
                ++safe_area;
            }
        }
    }

    if (safe_area > ANS)
    {
        ANS = safe_area;
    }
}

void bfs()
{
    queue<Pii> bfs_q;
    map_temp = map_origin;

    for (const auto &pos : wall)
    {
        map_temp[pos.first][pos.second] = 1;
    }

    for (const auto &v : virus)
    {
        bfs_q.push(v);
    }

    while (!bfs_q.empty())
    {
        int vx = bfs_q.front().first;
        int vy = bfs_q.front().second;
        bfs_q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = vx + dx[i];
            int ny = vy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (map_temp[nx][ny] == 0)
                {
                    map_temp[nx][ny] = 2;
                    bfs_q.push({nx, ny});
                }
            }
        }
    }

    check_area();
}

void combination(int depth, int start)
{
    if (depth == 3)
    {
        bfs();
        return;
    }

    for (int k = start; k < N * M; ++k)
    {
        int i = k / M;
        int j = k % M;

        if (map_origin[i][j] == 0)
        {
            wall[depth] = {i, j};
            combination(depth + 1, k + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map_origin[i][j];
            if (map_origin[i][j] == 2)
            {
                virus.push_back({i, j});
            }
        }
    }

    combination(0, 0);

    cout << ANS;

    return 0;
}