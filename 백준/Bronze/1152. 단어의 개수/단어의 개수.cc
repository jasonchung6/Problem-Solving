#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str1;
    getline(cin, str1);
    int sz;
    int sp = 0;
    sz = str1.size();
    for(int i = 0; i<sz; i++){
        if(str1.at(i) == ' ')
            sp++;
    }
    char fr = str1.front();
    char en = str1.back();
    if(fr == ' ' && en == ' ')
        sp--;
    else if(fr != ' ' && en != ' ')
        sp++;
    cout<<sp;
}