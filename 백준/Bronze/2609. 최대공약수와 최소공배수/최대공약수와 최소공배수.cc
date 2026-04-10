#include <iostream>
using namespace std;

int main()
{
    int i, j, y, g = 0, ij;

    cin >> i >> j;
    ij = i * j;
    for (int y1 = 1; y1 <= 10000; y1++)
    {
        if (i % y1 == 0 && j % y1 == 0)
            y = y1;
    }
    for (int g1 = 1; g1 <= ij; g1++)
    {
        if (g1 % i == 0 && g1 % j == 0)
            g = g1;
        if (g ^= 0)
            break;
    }
    cout << y << endl << g;
    return 0;
}