#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    stack<int> sta;
    queue<char> ans;
    int n, temp, num = 1;
    cin >> n;
    int *ptr1 = new int[n];

    for (int i = 0; i < n; i++)
        cin >> ptr1[i];

    for (int i = 0; i < n; i++){
        if (sta.empty() == 1){
            sta.push(num);
            num++;
            ans.push('+');
        }
        if (sta.top() < ptr1[i]){
            while ((num - 1) != ptr1[i]){
                sta.push(num);
                num++;
                ans.push('+');
            }
            sta.pop();
            ans.push('-');
        }
        else if (sta.top() == ptr1[i]){
            sta.pop();
            ans.push('-');
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    temp = ans.size();
    for (int i = 0; i < temp; i++){
        cout << ans.front() << '\n';
        ans.pop();
    }

    delete[] ptr1;
    return 0;
}