#include <iostream>
using namespace std;

int main (){
    int H = 0, M = 0;
    cin >> H >> M;

    if (M >= 45)
        M -= 45;
    else{
        M = 45 - M;
        M = 60 - M;
        if (H == 0)
            H = 24;
        H--;
    }
    cout << H << " " << M;
    
    
    return 0;
}