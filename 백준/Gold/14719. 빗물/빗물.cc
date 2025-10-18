#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H, W;
    int ANS = 0;
    int maxH = 0;
    stack<int> st;
    cin >> H >> W;
    
    while (W--)
    {
        int col;
        cin >> col;

        int cnt = 0;
        int n = col;
        while (!st.empty() && st.top() < col)
        {
            if (col > maxH && st.top() <= maxH)
            {
                ANS += maxH - st.top();
                st.pop();
            }
            else
            {
                ANS += col - st.top();
                st.pop();
                ++cnt;
            }
        }
        if (cnt)
        {
            for(int i = 0; i < cnt; ++i)
            {
                st.push(n);
            }
        }
        maxH = max(maxH, n);
        st.push(n);
    }

    cout << ANS;

    return 0;
}