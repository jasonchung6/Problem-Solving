#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int num = 1, sum, ANS = 0;
    cin >> N;

    while (num < N)
    {
        sum = num + num % 10 + num % 100 / 10 + num % 1'000 / 100 + num % 10'000 / 1'000 + num % 100'000 / 10'000 + num % 1'000'000 / 100'000;
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