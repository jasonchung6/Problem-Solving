#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int SIZE = 1001;

int N, M;
int parent[SIZE];

struct Edge
{
    int u, v, w;
    bool operator<(const Edge &other) const
    {
        return w < other.w;
    }
};

int findParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

void unionParent(int x, int y)
{
    x = findParent(x);
    y = findParent(y);
    if (x > y)
    {
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ANS = 0;
    vector<Edge> edges;

    cin >> N >> M;

    vector<bool> gender(N + 1);
    vector<bool> visited(N + 1, 0);

    for (int i = 1; i <= N; ++i)
    {
        char c;
        cin >> c;
        if (c == 'M')
            gender[i] = 1;
        else
            gender[i] = 0;

        parent[i] = i;
    }

    for (int i = 0; i < M; ++i)
    {
        int u, v, d;
        cin >> u >> v >> d;
        edges.push_back({u, v, d});
    }

    sort(edges.begin(), edges.end());

    for (const auto &edge : edges)
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        if (gender[u] != gender[v])
        {
            if (findParent(u) != findParent(v))
            {
                unionParent(u, v);
                ANS += w;
                visited[u] = 1;
                visited[v] = 1;
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        if (findParent(i) != 1)
            ANS = -1;
    }

    cout << ANS;

    return 0;
}