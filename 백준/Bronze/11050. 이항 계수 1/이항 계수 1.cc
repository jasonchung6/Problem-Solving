#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    cout << tgamma(n + 1) / tgamma(k + 1) / tgamma(n - k + 1);

    return 0;
}
