#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    string temp;
    cin >> n >> m;
    set<string> deud;
    set<string> deudbo;

    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        deud.insert(temp);
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> temp;
        if (deud.find(temp) != deud.end())
            deudbo.insert(temp);
    }
    cout << deudbo.size() << "\n";
    for (const auto &elem : deudbo)
        cout << elem << "\n";

    return 0;
}