#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

using Pii = pair<long long, long long>;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long double ANS = 0;
	cin >> N;
	vector<Pii> point(N + 1);

	for (int i = 0; i < N; ++i)
	{
		cin >> point[i].first >> point[i].second;
	}
	point[N] = point[0];

	for (int i = 0; i < N; ++i)
	{
		ANS += point[i].first * point[i + 1].second - point[i].second * point[i + 1].first;
	}
    
	ANS = abs(ANS) / 2.0;
	cout << fixed << setprecision(1);
	cout << ANS;

	return 0;
}