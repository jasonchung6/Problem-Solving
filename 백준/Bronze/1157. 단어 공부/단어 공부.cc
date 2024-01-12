#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

string word;
cin >> word;
int max = 0;
int cnt = 0;
int target;
int a[26] = {0,};
transform(word.begin(), word.end(), word.begin(), (int(*)(int))toupper);
for(int i=0; i < word.length(); i++){
    a[word[i] - 'A']++;
    }

for(int i = 0; i < 26; i++){
    if(max < a[i]){
        max = a[i];
        cnt = 0;
        target = i;
        }
    if(max == a[i])
        cnt++;
    }
    if(cnt > 1)
        cout << "?";
    else
        cout << (char)(target+'A');
}