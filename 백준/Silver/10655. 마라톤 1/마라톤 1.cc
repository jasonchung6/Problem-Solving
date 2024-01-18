#include <iostream>

using namespace std;

int main() {
    int n, disx, disy;
    int x[100002];
    int y[100002];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    int totalDis = 0;
    for (int i = 1; i < n; i++) {//전체 dis 계산
        disx = abs(x[i] - x[i + 1]);
        disy = abs(y[i] - y[i + 1]);
        totalDis += (disx + disy);
    }

    int minDis = totalDis;
    int temp = 0;
    for (int i = 2; i < n; i++) {//빠지는 체크포인트
        temp = totalDis;
        disx = abs(x[i - 1] - x[i]);
        disy = abs(y[i - 1] - y[i]);
        temp -= (disx + disy);
        disx = abs(x[i] - x[i + 1]);
        disy = abs(y[i] - y[i + 1]);
        temp -= (disx + disy);

        disx = abs(x[i - 1] - x[i + 1]);
        disy = abs(y[i - 1] - y[i + 1]);
        temp += (disx + disy);

        minDis = min(temp, minDis);
    }
    
    cout << minDis;
    return 0;
}