#include <iostream>
using namespace std;

int main (){
    int temp = 0, num = 0, sol = 0;
    for (int i = 0; i < 5; i++)
    {
        cin>>temp;
        num += temp*temp;
    }
    sol = num % 10;
    cout << sol;

    return 0;
}