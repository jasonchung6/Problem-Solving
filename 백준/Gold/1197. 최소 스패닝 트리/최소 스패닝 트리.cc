#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int u;
	int v;
	int w;

	bool operator<(const Edge& e)const {
		return this->w < e.w;
	}
};

int find(vector<int>& parent, int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent, parent[a]);
}

void unify(vector<int>& parent, int a, int b) {
	int rootA = find(parent, a);
	int rootB = find(parent, b);

	if (rootA < rootB) {
		parent[rootB] = rootA;
	}
	else {
		parent[rootA] = rootB;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, E;
	cin >> V >> E;

	vector<Edge> edges;
	vector<int> parent(V + 1);
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({ u,v,w });
	}
	sort(edges.begin(), edges.end());

	for (int i = 1; i <= V; ++i) {
		parent[i] = i;
	}

	int selected = 1;
	int ANS = 0;
	for (int i = 0; i < E; ++i) {
		int u = edges[i].u;
		int v = edges[i].v;
		if (find(parent, u) != find(parent, v)) {
			unify(parent, u, v);
			++selected;
			ANS += edges[i].w;
		}
		if (selected == E) {
			break;
		}
	}

	cout << ANS;

    return 0;
}