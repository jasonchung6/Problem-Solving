#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define L first
#define H second

using PII = pair<int, int>;
constexpr int MAX_PWR = 5001;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int ANS = 0;
    int maxH = 0;
    int prevH, prevL;
    cin >> N;
    vector<PII> cols(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> cols[i].L >> cols[i].H;
    }

    sort(cols.begin(), cols.end());

    for (int i = 0; i < N; ++i)
    {
        if (cols[maxH].H < cols[i].H)
        {
            maxH = i;
        }
    }

    ANS = cols[maxH].H;
    prevL = cols[0].L;
    prevH = cols[0].H;

    for (auto col : cols)
    {
        if (col.H >= prevH)
        {
            ANS += (col.L - prevL) * prevH;
            prevL = col.L;
            prevH = col.H;
        }
    }

    prevL = cols[N - 1].L;
    prevH = cols[N - 1].H;

    for (int i = N - 2; i > 0; --i)
    {
        if (cols[i].H > prevH)
        {
            ANS += (prevL - cols[i].L) * prevH;
            prevL = cols[i].L;
            prevH = cols[i].H;
        }
    }

    cout << ANS;

    return 0;
}