#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1;
    cin >> s1;
    if(s1.at(0) == 'E')
        cout<<"I";
    else
        cout<<"E";
    if(s1.at(1) == 'S')
        cout<<"N";
    else
        cout<<"S";
    if(s1.at(2) == 'T')
        cout<<"F";
    else
        cout<<"T";
    if(s1.at(3) == 'J')
        cout<<"P";
    else
        cout<<"J";
}