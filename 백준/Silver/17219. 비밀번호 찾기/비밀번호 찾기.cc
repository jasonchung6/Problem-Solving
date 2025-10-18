#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

using PII = pair<int, int>;
constexpr int MAX_PWR = 5001;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    unordered_map<string, string> mp;

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        string site, pw;
        cin >> site >> pw;
        mp.insert({ site, pw });
    }

    for (int i = 0; i < M; ++i)
    {
        string site;
        cin >> site;
        cout << mp[site] << '\n';
    }

    return 0;
}