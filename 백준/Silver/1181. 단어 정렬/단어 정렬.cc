#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, temp_sz = 0, temp_num = 0;
    string str1[20000], str_temp;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> str1[i];
    for (int i = 0; i < n; i++)
    {
        temp_sz = str1[i].size();
        temp_num = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (str1[j].size() < temp_sz)
            {
                temp_num = j;
                temp_sz = str1[j].size();
            }
        }
        if (temp_sz < str1[i].size())
        {
            str_temp = str1[i];
            str1[i] = str1[temp_num];
            str1[temp_num] = str_temp;
        }
    }
    
    temp_sz = str1[0].size();
    temp_num = 0;
    for (int i = 1; i < n+1; i++)
    {
        if (temp_sz != str1[i].size())
        {
            sort(str1 + temp_num, str1 + i);
            temp_num = i;
            temp_sz = str1[i].size();
        }
    }

    cout << str1[0] << endl;
    for (int i = 1; i < n; i++)
    {
        if (str1[i] != str1[i - 1])
            cout << str1[i] << endl;
    }

    return 0;
}