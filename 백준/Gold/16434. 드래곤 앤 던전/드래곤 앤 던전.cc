#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll h_atk;
    cin >> n >> h_atk;

    ll cur_damage = 0;
    ll max_damage = 0;

    for (int i = 0; i < n; ++i) {
        int t;
        ll a, h;
        cin >> t >> a >> h;

        if (t == 1) {
            ll attack_count = (h - 1) / h_atk;
            cur_damage += attack_count * a;

            if (cur_damage > max_damage) {
                max_damage = cur_damage;
            }
        } else {
            h_atk += a;
            cur_damage -= h;

            if (cur_damage < 0) {
                cur_damage = 0;
            }
        }
    }

    cout << max_damage + 1;

    return 0;
}