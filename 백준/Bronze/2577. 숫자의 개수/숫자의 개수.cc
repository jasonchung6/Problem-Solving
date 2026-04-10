#include <iostream>
#include <vector>
using namespace std;

int main() {
    int num[3] = {0,};
    int count[10] = {0,};
    int na, div = 10;
    for (int i = 0; i < 3; i++)
    {
        cin >> num[i];
    }
    num[1] *= num[0];
    num[2] *= num[1];
    for (int i = 0; i < 9; i++)
    {
        na = num[2] % div;
        count[na]++;
        num[2] /= 10;
        if (num[2] == 0)
            break;
    }
    for (int i = 0; i < 10; i++)
        cout << count[i] <<"\n";
}