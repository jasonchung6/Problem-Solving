#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 7, k = 3;
    cin >> n >> k;
    vector<int> vec;
    for (int i = 0; i < n; i++)
        vec.push_back(i + 1);
    cout << "<";
    int pos = --k;
    for (int i = 0; i < n; i++)
    {
        cout << vec[pos];
        vec.erase(vec.begin() + pos);
        pos += k;
        // if (pos > vec.size())
        while (pos > vec.size() - 1)
            pos -= vec.size();
        if (i == n - 1)
            break;
        else
            cout << ", ";
    }
    cout << ">";

    return 0;
}
