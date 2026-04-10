#include <iostream>
using namespace std;
int main(){ int n ,m ,i ,j; char a[100][21] = {}; cin >> n; for(i = 0; i < n; i++){ int b ,l ,max = 0; cin >> m; for(j = 0; j < m; j++){ cin >> b; cin >> a[j]; if(b > max){ max = b; l = j; } } cout << a[l] << endl; } return 0; }
