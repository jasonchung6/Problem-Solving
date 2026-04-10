#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> n;
    int k = 0, temp = 0;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> temp;
        if (temp != 0)
            n.push_back(temp);
        else
            n.pop_back();
    }
    temp = 0;
    for (int i = 0; i < n.size(); i++)
        temp += n[i];
    cout << temp;

    return 0;
}