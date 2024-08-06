#include <iostream>
#include <queue>
#include <string>
using namespace std;

#define endl '\n'

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, temp;
	string str;
	queue<int> q;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "push") {
			cin >> temp;
			q.push(temp);
		}
		else if (str == "pop") {
			if (q.empty())
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << endl;
		}
		else if (str == "empty") {
			cout << q.empty() << endl;
		}
		else if (str == "front") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.front() << endl;
		}
		else if (str == "back") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.back() << endl;
		}
	}
	return 0;
}