#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n, count = 1, ans = 666;
	string temp, str1;
	cin >> n;
	while (count != n)
	{
		ans++;
		str1 = to_string(ans);
		for (int i = 0; i < str1.size() - 2; i++)
		{
			temp = str1.substr(i, 3);
			if (temp.compare("666") == 0)
			{
				count++;
				break;
			}
		}
	}
	cout << ans;
}