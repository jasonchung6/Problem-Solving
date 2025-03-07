#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[101][101] = { 0, };
queue<pair<int, int>> q;

bool isValid(int x, int y)
{
    if (x >= 0 && x < N && y >= 0 && y < N)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void bfs(vector<string> &pic)
{
    int x = q.front().first;
    int y = q.front().second;
    int xx;
    int yy;
    char color = pic[x][y];
    while (q.empty() == 0)
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        visited[x][y] = 1;
        for (int i = 0; i < 4; ++i)
        {
            xx = x + dx[i];
            yy = y + dy[i];
            if (isValid(xx, yy) == true && visited[xx][yy] == 0)
            {
                if (pic[xx][yy] == color)
                {
                    visited[xx][yy] = 1;
                    q.push({ xx,yy });
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ANS = 0;
    int ANSRG = 0;
    cin >> N;
    vector<string> pic(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> pic[i];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (visited[i][j] == 0)
            {
                q.push({ i,j });
                bfs(pic);
                ++ANS;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            visited[i][j] = 0;
            if (pic[i][j] == 'G')
            {
                pic[i][j] = 'R';
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (visited[i][j] == 0)
            {
                q.push({ i,j });
                bfs(pic);
                ++ANSRG;
            }
        }
    }

    cout << ANS << " " << ANSRG;

	return 0;
}