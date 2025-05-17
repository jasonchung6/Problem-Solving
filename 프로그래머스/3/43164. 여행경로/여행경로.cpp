#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

bool dfs(int n, map<string, vector<pair<string, bool>>>& mp, string va, stack<string>& stk){
    stk.push(va);
    if(stk.size() == n){
        return true;
    }

    for(auto& na : mp[va]){
        if(!na.second){
            na.second = true;
            if(dfs(n, mp, na.first, stk)){
                return true;
            }
            else{
                stk.pop();
                na.second = false;
            }
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    map<string, vector<pair<string, bool>>> mp;
    for(const auto& ticket : tickets){
        mp[ticket[0]].push_back({ticket[1], false});
    }
    
    stack<string> stk;
    dfs(tickets.size() + 1, mp, "ICN", stk);
    answer.reserve(stk.size());
    while(!stk.empty()){
        answer.push_back(stk.top());
        stk.pop();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}