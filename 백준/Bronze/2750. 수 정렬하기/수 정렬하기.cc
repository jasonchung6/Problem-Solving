#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> vec)
{
    if (vec.size() <= 1)
        return vec;
    int m = vec.size() / 2;
    vector<int> left(vec.begin(), vec.begin() + m);
    vector<int> right(vec.begin() + m, vec.end());
    left = mergeSort(left);
    right = mergeSort(right);

    vector<int> result;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }

    while (i < left.size())
        result.push_back(left[i++]);
    while (j < right.size())
        result.push_back(right[j++]);

    return result;
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
        cin >> vec[i];

    vec = mergeSort(vec);

    for (int i = 0; i < n; i++)
        cout << vec[i] << "\n";

    return 0;
}