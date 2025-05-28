#include <iostream>
#include <stack>
 #include <string>
using namespace std;

int priority(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string inpix;
	stack<char> oper;
	cin >> inpix;

	for (const char& c : inpix) {
        if ('A' <= c && c <= 'Z') {
            cout << c;
        }
        else if (c == '(') {
            oper.push(c);
        }
        else if (c == ')') {
            while (!oper.empty() && oper.top() != '(') {
                cout << oper.top();
                oper.pop();
            }
            oper.pop();
        }
        else {
            while (!oper.empty() && priority(oper.top()) >= priority(c)) {
                if (oper.top() == '(') break;
                cout << oper.top();
                oper.pop();
            }
            oper.push(c);
        }
    }

	while (!oper.empty()) {
		cout << oper.top();
		oper.pop();
	}

	return 0;
}