#include <iostream>
using namespace std;

int main()
{
    int n = 0, k = 0, ans = 0, temp = 0;
    cin >> n >> k;
    int a[10];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > k)
            a[i] = 0;
    }
    for (int i = n-1; i > -1; i--)
    {
        if (a[i] != 0)
        {
            temp = k;
            temp /= a[i];
            ans += temp;
            k = k - temp * a[i];
        }
    }
    cout << ans;

    return 0;
}