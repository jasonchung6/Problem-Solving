#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> card(n);
    for (int i = 0; i < n; i++)
        cin >> card[i];
    sort(card.begin(), card.end());
    int max = 0, temp;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                temp = card[i] + card[j] + card[k];
                if (temp <= m && temp > max)
                    max = temp;
            }
        }
    }
    cout << max;
    return 0;
}
