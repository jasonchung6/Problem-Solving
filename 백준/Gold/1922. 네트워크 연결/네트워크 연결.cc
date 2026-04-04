#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int parent[10001];
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
    {
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<Edge> edges;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    for (int i = 0; i < N; ++i)
    {
        parent[i] = i;
    }

    sort(edges.begin(), edges.end());

    int result = 0;
    for (int i = 0; i < edges.size(); ++i)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (findParent(u) != findParent(v))
        {
            unionParent(u, v);
            result += w;
        }
    }

    cout << result;

    return 0;
}