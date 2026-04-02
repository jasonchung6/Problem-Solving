#include <iostream>
#include <vector>
using namespace std;

constexpr int SIZE = 51;
vector<vector<int>> A(SIZE, vector<int>(SIZE, 0));
vector<vector<int>> A_next(SIZE, vector<int>(SIZE, 0));
vector<int> puri;

int R, C, T;
int ANS = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

inline bool isInside(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

void diffuse()
{
    int diff_dust = 0;
    A_next.assign(SIZE, vector<int>(SIZE, 0));
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (A[i][j] > 4)
            {
                int diff_count = 0;
                diff_dust = A[i][j] / 5;
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (isInside(nx, ny))
                    {
                        if (ny == 0)
                        {
                            if (nx == puri[0] || nx == puri[1])
                            {
                                continue;
                            }
                        }
                        A_next[nx][ny] += diff_dust;
                        ++diff_count;
                    }
                }
                A_next[i][j] += (A[i][j] - (diff_dust * diff_count));
            }
            else
            {
                A_next[i][j] += A[i][j];
            }
        }
    }
}

void move()
{
    for (int x = puri[0] - 1; x > 0; --x)
    {
        A_next[x][0] = A_next[x - 1][0];
    }
    for (int x = puri[1] + 1; x < R - 1; ++x)
    {
        A_next[x][0] = A_next[x + 1][0];
    }

    for (int y = 0; y < C - 1; ++y)
    {
        A_next[0][y] = A_next[0][y + 1];
        A_next[R - 1][y] = A_next[R - 1][y + 1];
    }

    for (int x = 0; x < puri[0]; ++x)
    {
        A_next[x][C - 1] = A_next[x + 1][C - 1];
    }
    for (int x = R - 1; x > puri[1]; --x)
    {
        A_next[x][C - 1] = A_next[x - 1][C - 1];
    }

    for (int y = C - 1; y > 1; --y)
    {
        A_next[puri[0]][y] = A_next[puri[0]][y - 1];
        A_next[puri[1]][y] = A_next[puri[1]][y - 1];
    }
    A_next[puri[0]][1] = 0;
    A_next[puri[1]][1] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> A[i][j];
            if (A[i][j] == -1)
            {
                puri.push_back(i);
            }
        }
    }

    while (T--)
    {
        diffuse();
        move();
        A = A_next;
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            ANS += A[i][j];
        }
    }

    cout << ANS + 2;

    return 0;
}