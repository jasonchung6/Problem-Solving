#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int n[3];
	while (true)
	{
		cin >> n[0] >> n[1] >> n[2];
		sort(n, n + 3);
		if (n[0] == 0)
			break;
		else if (n[2] * n[2] == n[1] * n[1] + n[0] * n[0])
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}