#include <iostream>
using namespace std;

int main(void){
    int num = 1, n[5] = { 0, };
    while (num != 0){
        cin >> num;
        n[0] = num / 10000;
        n[1] = num / 1000;
        n[1] %= 10;
        n[2] = num / 100;
        n[2] %= 10;
        n[3] = num / 10;
        n[3] %= 10;
        n[4] = num % 10;

        if (n[0] != 0){
            if (n[0] == n[4] && n[1] == n[3])
                cout << "yes" <<endl;
            else
                cout << "no" <<endl;
        }
        else if (n[1] != 0){
            if (n[1] == n[4] && n[2] == n[3])
                cout << "yes" <<endl;
            else
                cout << "no" <<endl;
        }
        else if (n[2] != 0){
            if (n[2] == n[4])
                cout << "yes" <<endl;
            else
                cout << "no" <<endl;
        }
        else if (n[3] != 0){
            if (n[3] == n[4])
                cout << "yes" <<endl;
            else
                cout << "no" <<endl;
        }
        else if(n[4] != 0)
            cout << "yes" <<endl;
        else{}
    }
}