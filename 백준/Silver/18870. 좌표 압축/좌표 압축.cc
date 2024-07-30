#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    
    vector<int> comp{ x };
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());

    for (int i = 0; i < n; ++i)
        cout << lower_bound(comp.begin(), comp.end(), x[i]) - comp.begin() << " ";

	return 0;
}