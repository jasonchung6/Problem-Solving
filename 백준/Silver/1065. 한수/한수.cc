#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    int count = 0;
    cin >> n;
    int intn = stoi(n);
    if (intn <= 99)
        cout << intn;
    else if (intn < 111)
        cout << "99";
    else if (intn == 1000)
        cout << "144";
    else if (intn >= 111)
    {
        for (int i = 111; i <= intn; i++)
        {
            int a = i % 10;
            int b = i % 100 / 10;
            int c = i % 1000 / 100;
            if (b - a == c - b) count++;
        }
        int sol = 99 + count;
        cout << sol;
    }
    return 0;
}