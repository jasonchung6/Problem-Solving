#include<iostream>
using namespace std;
int main(){
int N, max = 0, hap = 0;
cin >> N;
int jumsu[N];
for(int i = 0; i < N; i++){
    cin >> jumsu[i];
    if(jumsu[i] > max)
        max = jumsu[i];
    hap += jumsu[i];
    }
cout<<(float)hap/max/N*100;
}