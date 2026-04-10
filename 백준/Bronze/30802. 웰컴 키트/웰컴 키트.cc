#include <iostream>
using namespace std;

int main()
{
    int n, s, m, l, xl, xxl, xxxl, t, p; // 2<=tp
    int shirt = 0, pen1, pen2;
    cin >> n >> s >> m >> l >> xl >> xxl >> xxxl >> t >> p;
    // shirt
    shirt = s / t;
    shirt += m / t;
    shirt += l / t;
    shirt += xl / t;
    shirt += xxl / t;
    shirt += xxxl / t;
    if (s % t != 0)
        shirt++;
    if (m % t != 0)
        shirt++;
    if (l % t != 0)
        shirt++;
    if (xl % t != 0)
        shirt++;
    if (xxl % t != 0)
        shirt++;
    if (xxxl % t != 0)
        shirt++;
    // pen
    pen1 = n / p;
    pen2 = n % p;
    cout << shirt << "\n"
         << pen1 << " " << pen2;
    return 0;
}