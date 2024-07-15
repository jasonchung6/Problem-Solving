#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Data
{
    int age;
    string name;

    bool operator<(const Data &other) const
    {
        return age < other.age;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Data> vec(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i].age >> vec[i].name;
    stable_sort(vec.begin(), vec.end());
    for (const auto &item : vec)
        cout << item.age << " " << item.name << "\n";
    return 0;
}