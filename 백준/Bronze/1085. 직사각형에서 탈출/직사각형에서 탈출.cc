#include <iostream>
using namespace std;

int main()
{
	int x , y , w , h;
	cin >> x >> y >> w >> h;
	int low = x;
	if (low > y)
		low = y;
	if (low > w - x)
		low = w - x;
	if (low > h - y)
		low = h - y;
	cout << low;
	return 0;
}