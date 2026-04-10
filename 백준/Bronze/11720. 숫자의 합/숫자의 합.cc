#include<iostream>
#include<string>
using namespace std;

int main() {
    int N, sum=0;
    string str, temp;
    cin >> N >> str;
    for(int i = 0; i < N; i++){
        temp = str.at(i);
        sum += stoi(temp);
        }
    cout<< sum;
}