#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Pii = pair<int, int>;
constexpr int SIZE = 103;
vector<vector<bool>> apple(SIZE, vector<bool>(SIZE, 0));
queue<Pii> q;
deque<Pii> dq;

int N, K, L;
int SEC = 1;
int DIR = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool move()
{
    int nx = dq.front().first + dx[DIR];
    int ny = dq.front().second + dy[DIR];

    if (nx < 1 || nx > N || ny < 1 || ny > N)
    {
        return false;
    }

    for (const auto &body : dq)
    {
        if (body == Pii{nx, ny})
        {
            return false;
        }
    }

    dq.push_front({nx, ny});
    if (!apple[nx][ny])
    {
        dq.pop_back();
    }
    else
    {
        apple[nx][ny] = 0;
    }

    
    if (!q.empty())
    {
        if (q.front().first == SEC)
        {
            if (q.front().second == 'D')
            {
                DIR = (DIR + 1) % 4;
            }
            else
            {
                DIR = (DIR - 1 + 4) % 4;
            }
            q.pop();
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    int x, y;
    char c;

    for (int i = 0; i < K; ++i)
    {
        cin >> x >> y;
        apple[x][y] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; ++i)
    {
        cin >> x >> c;
        q.push({x, (int)c});
    }
    dq.push_back({1, 1});

    while (move())
    {
        ++SEC;
    }

    cout << SEC;

    return 0;
}