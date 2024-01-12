#include<iostream>
using namespace std;

int main()
{
	int a = 0, b = 0, sum = 0;
	int count = 0, sutja = 1;
	int* arr;
	cin >> a >> b;
	arr = new int[b];
	for (int i = 0; ; i++)
	{
		for (int j = 0; j < sutja; j++)
		{
			arr[count] = sutja;
			count++;
			if (count == b)
				break;
		}
		if (count == b)
			break;
		sutja++;
	}
	for (int i = a - 1; i < b; i++)
	{
		sum += arr[i];
	}
	cout << sum;
	delete[] arr;
	return 0;
}