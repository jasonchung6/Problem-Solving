#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define endl '\n'

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, temp;
	string str;
	stack<int> stk;
	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "push") {
			cin >> temp;
			stk.push(temp);
		}
		else if (str == "pop") {
			if (stk.empty())
				cout << -1 << endl;
			else {
				cout << stk.top() << endl;
				stk.pop();
			}
		}
		else if (str == "size") {
			cout << stk.size() << endl;
		}
		else if (str == "empty") {
			cout << stk.empty() << endl;
		}
		else if (str == "top") {
			if (stk.empty())
				cout << -1 << endl;
			else
				cout << stk.top() << endl;
		}
	}
	return 0;
}