#include <iostream>
#include <queue>
using namespace std;

int main (){
    int n = 0, temp = 0;
    queue<int> q;
    cin >> n;
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (q.size() != 1)
    {
        q.pop();
        temp = q.front();
        q.push(temp);
        q.pop();
    }

    cout << q.back();

    return 0;
}