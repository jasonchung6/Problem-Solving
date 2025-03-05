#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);

	int L1, L2, L3;
	int temp = 0;
	
	while (1)
	{
		cin >> L1 >> L2 >> L3;
		if (L1 == 0 && L2 == 0 && L3 == 0)
		{
			break;
		}
		
		if (L1 == L2 && L2 == L3)
		{
			cout << "Equilateral\n";
			continue;
		}
		
		if (L1 > L2)
		{
			swap(L1, L2);
		}
		if (L1 > L3)
		{
			swap(L1, L3);
		}		
		if (L2 > L3)
		{
			swap(L2, L3);
		}

		if (L3 >= (L1 + L2))
		{
			cout << "Invalid\n";
			continue;
		}

		if (L1 == L2 || L1 == L3 || L2 == L3)
		{
			cout << "Isosceles\n";
			continue;
		}

		cout << "Scalene\n";
	}

	return 0;
}