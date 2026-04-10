#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    char a[101] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = '*';
        cout << a << endl;
    }

    return 0;
}