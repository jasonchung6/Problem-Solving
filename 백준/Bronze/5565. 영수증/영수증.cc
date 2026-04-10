#include <iostream>
using namespace std;

int main (){
    int num[10];
    for (int i = 0; i < 10; i++)
    {
        cin>>num[i];
        if (i^=0)
            num[0]-=num[i];
    }
    cout << num[0];
    return 0;
}