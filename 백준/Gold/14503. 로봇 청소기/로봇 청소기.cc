#include <iostream>
#include <vector>
using namespace std;

constexpr int SIZE = 51;
vector<vector<int>> room(SIZE, vector<int>(SIZE, 0));
int N, M;
int r, c, d;
int ANS = 0;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

bool canClean()
{
    int nx, ny;
    for (int i = 0; i < 4; ++i)
    {
        nx = r + dx[i];
        ny = c + dy[i];
        if (room[nx][ny] == 0)
        {
            return true;
        }
    }
    return false;
}

void robot()
{
    int nx, ny;
    bool wall = 0;

    while (wall == 0)
    {
        if (room[r][c] == 0)
        {
            room[r][c] = 2;
            ++ANS;
        }

        if (!canClean())
        {
            nx = r - dx[d];
            ny = c - dy[d];
            if (room[nx][ny] == 1)
            {
                wall = 1;
            }
            else
            {
                r = nx;
                c = ny;
            }
        }
        else
        {
            for (int i = 0; i < 4; ++i)
            {
                d = (d + 1) % 4;
                nx = r + dx[d];
                ny = c + dy[d];
                if (room[nx][ny] == 0)
                {
                    r = nx;
                    c = ny;
                    break;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    cin >> r >> c >> d;

    if (d == 1)
    {
        d = 3;
    }
    else if (d == 3)
    {
        d = 1;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> room[i][j];
        }
    }

    robot();
    cout << ANS;

    return 0;

}