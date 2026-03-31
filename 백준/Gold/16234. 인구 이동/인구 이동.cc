#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using Pii = pair<int, int>;
constexpr int SIZE = 51;
vector<vector<int>> A(SIZE, vector<int>(SIZE, 0));
vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, 0));
queue<Pii> q;
queue<Pii> q2;

int N, L, R;
int ANS = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool moved = 0;

void bfs()
{
    int popul_diff;
    int sum_popul = 0;
    int vx, vy, nx, ny;

    while (!q.empty())
    {
        vx = q.front().first;
        vy = q.front().second;
        q.pop();

        if (!visited[vx][vy])
        {
            q2.push({vx, vy});
            sum_popul += A[vx][vy];
            visited[vx][vy] = 1;
            for (int i = 0; i < 4; ++i)
            {
                nx = vx + dx[i];
                ny = vy + dy[i];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N)
                {
                    if (!visited[nx][ny])
                    {
                        popul_diff = abs(A[vx][vy] - A[nx][ny]);
                        if (L <= popul_diff && popul_diff <= R)
                        {
                            q.push({nx, ny});
                            moved = 1;
                        }
                    }
                }
            }
        }
    }

    sum_popul /= q2.size();

    while (!q2.empty())
    {
        A[q2.front().first][q2.front().second] = sum_popul;
        q2.pop();
    }
}

bool move()
{
    moved = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!visited[i][j])
            {
                q.push({i, j});
                bfs();
            }
        }
    }
    return moved;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> A[i][j];
        }
    }

    while (move())
    {
        ++ANS;
        visited.assign(SIZE, vector<bool>(SIZE, 0));
    }

    cout << ANS;

    return 0;
}