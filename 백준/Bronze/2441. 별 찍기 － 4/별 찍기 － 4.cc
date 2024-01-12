#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int n2 = n;
    for (int i = 1; i <= n2; i++)
    {
        for (int k = i; k > 1; k--)
            cout << " ";
        for (int j = n; j ^= 0; j--)
            cout << "*";
        n--;
        cout << endl;
    }
    return 0;
}