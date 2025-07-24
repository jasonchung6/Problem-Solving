#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using Pii = pair<int, int>;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K, ANS;
    int hor_max = 0, ver_max = 0;
    int hor_small, ver_small;
    int hor_idx, ver_idx;
    cin >> K;
    vector<Pii> line(7);
    for (int i = 0; i < 6; ++i)
    {
        int dir, len;
        cin >> dir >> len;
        line[i] = {dir, len};
        if (dir < 3)
        {
            if (hor_max < len)
            {
                hor_max = len;
                hor_idx = i;
            }
        }
        else
        {
            if (ver_max < len)
            {
                ver_max = len;
                ver_idx = i;
            }
        }
    }

    ANS = hor_max * ver_max;
    hor_small = abs(line[(hor_idx + 5) % 6].second - line[(hor_idx + 1) % 6].second);
    ver_small = abs(line[(ver_idx + 5) % 6].second - line[(ver_idx + 1) % 6].second);
    ANS -= hor_small * ver_small;
    ANS *= K;
    cout << ANS;

    return 0;
}