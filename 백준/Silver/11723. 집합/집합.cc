#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, temp;
    string cmd;
    set<int> s;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> cmd;
        if (cmd == "add")
        {
            cin >> temp;
            s.insert(temp);
        }
        else if (cmd == "remove")
        {
            cin >> temp;
            s.erase(temp);
        }
        else if (cmd == "check")
        {
            cin >> temp;
            if (s.find(temp) != s.end())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (cmd == "toggle")
        {
            cin >> temp;
            if (s.find(temp) != s.end())
                s.erase(temp);
            else
                s.insert(temp);
        }
        else if (cmd == "all")
            for (int i = 1; i < 21; ++i)
                s.insert(i);
        else if (cmd == "empty")
            s.clear();
    }

    return 0;
}