#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;
    long long low = 1;
    long long high = N;
    long long mid;
    int res;

    while (low <= high) {
        mid = (low + high) / 2;

        cout << "? " << mid << endl;
        cin >> res;

        if (res == 0) {
            cout << "= " << mid << endl;
            return 0;
        }
        else if (res == -1) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

	return 0;
}