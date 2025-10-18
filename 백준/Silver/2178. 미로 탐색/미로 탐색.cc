#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

using PII = pair<int, int>;
constexpr int SIZE = 101;
vector<vector<int>> miro(SIZE, vector<int>(SIZE, 0));
vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, 0));
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs()
{
    int vx, vy;
    queue<PII> q;
    q.push({ 0,0 });

    while (!q.empty())
    {
        vx = q.front().first;
        vy = q.front().second;
        visited[vx][vy] = 1;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = vx + dx[i];
            int ny = vy + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && miro[nx][ny] != 0 &&
                !visited[nx][ny])
            {
                miro[nx][ny] = miro[vx][vy] + 1;
                visited[nx][ny] = 1;
                if (nx == M - 1 && ny == N - 1)
                {
                    return;
                }
                q.push({ nx, ny });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j)
        {
            miro[i][j] = ((int)str[j] - 48);
        }
    }
    bfs();
    cout << miro[N - 1][M - 1];
    return 0;
}