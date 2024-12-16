#include <iostream>
#include <queue>
#include <stack>
using namespace std;

constexpr int SIZE = 200'001;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, k2, temp, cur = 0;
	cin >> n >> k;

	k2 = 2 * k;
	int vec[SIZE] = { 0, };
	int parent[SIZE] = { 0, };
	queue<int> q;
	parent[n] = n;
	vec[n] = 1;
	q.push(n);

	while (!vec[k])
	{
		cur = q.front();
		q.pop();

		temp = cur + 1;
		if (temp < SIZE && vec[temp] == 0)
		{
			vec[temp] = vec[cur] + 1;
			parent[temp] = cur;
			q.push(temp);
		}

		temp = cur - 1;
		if (temp >= 0 && vec[temp] == 0)
		{
			vec[temp] = vec[cur] + 1;
			parent[temp] = cur;
			q.push(temp);
		}

		temp = cur * 2;
		if (temp < k2 && vec[temp] == 0)
		{
			vec[temp] = vec[cur] + 1;
			parent[temp] = cur;
			q.push(temp);
		}
	}

	cout << --vec[k] << '\n';
	cur = k;
	stack<int> st;
	st.push(k);
	for (int i = 0; i < vec[k]; i++)
	{
		cur = parent[cur];
		st.push(cur);
	}
	for (int i = 0; i < vec[k]; i++)
	{
		cur = st.top();
		st.pop();
		cout << cur << " ";
	}
	cout << k;

	return 0;
}