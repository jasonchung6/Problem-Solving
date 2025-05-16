#include <string>
#include <vector>

using namespace std;

int CNT;

void dfs(const vector<int>& numbers, int target, int depth, int value){
    if(depth == numbers.size()){
        if(target == value){
            ++CNT;
        }
        return;
    }
    
    dfs(numbers, target, depth + 1, value + numbers[depth]);
    dfs(numbers, target, depth + 1, value - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return CNT;
}