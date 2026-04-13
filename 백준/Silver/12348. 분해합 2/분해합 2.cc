#include <iostream>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll N;
    ll num, sum, ANS = 0;
    cin >> N;
    num = N - 162;
    if (num < 1)
    {
        num = 1;
    }

    while (num < N)
    {
        sum = num;
        for (int i = 0; i < 18; ++i)
        {
            ll pow1;
            ll pow2 = 1;

            for (int j = 0; j < i; ++j)
            {
                pow2 *= 10;
            }
            pow1 = pow2 * 10;
            sum += (num % pow1) / pow2;
        }
        if (sum == N)
        {
            ANS = num;
            break;
        }
        ++num;
    }

    cout << ANS;

    return 0;
}