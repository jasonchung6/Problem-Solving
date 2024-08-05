#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define endl '\n'

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pq;

	int n, temp;
	cin >> n;

	while (n--)
	{
		cin >> temp;
		if (temp == 0)
		{	
			if (pq.empty())
				cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(temp);
		}
	}

	return 0;
}