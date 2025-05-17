#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();
    
    vector<vector<int>> DP(2, vector<int>(size + 2, 0));
    DP[0][0] = money[0];
    DP[0][1] = DP[0][0];
    DP[1][1] = money[1];
    
    for(int i = 2; i <= size; ++i){
        DP[0][i] = max(DP[0][i-2] + money[i], DP[0][i-1]);
        DP[1][i] = max(DP[1][i-2] + money[i], DP[1][i-1]);
    }
        
    answer = max(DP[0][size-2], DP[1][size-1]);
    return answer;
}