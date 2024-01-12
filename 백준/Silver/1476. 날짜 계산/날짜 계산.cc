#include<iostream>
using namespace std;

int main() {
	int E = 1, S = 1, M = 1, Y = 1;
	int ee = 0, ss = 0, mm = 0;

	cin >> ee >> ss >> mm;

	for (int i = 0; i < 7980; i++)
	{
		if (E == ee && S == ss && M == mm)
		{
			cout << Y;
			return 0;
		}
		E++, S++, M++, Y++;	
		if (E == 16)
			E = 1;
		if (S == 29)
			S = 1;
		if (M == 20)
			M = 1;
	}
	return 0;
}