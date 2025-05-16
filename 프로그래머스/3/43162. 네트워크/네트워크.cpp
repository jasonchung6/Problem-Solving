#include <string>
#include <vector>
#include <queue>
using namespace std;

void bfs(int n, const vector<vector<int>>& computers, vector<bool>& visited, queue<int>& q){
    while(!q.empty()){
        int vc = q.front();
        q.pop();
        visited[vc] = true;
        for(int i = 0; i < n; ++i){
            if(computers[vc][i] == 1 && visited[i] == false){
                visited[i] = true;
                q.push(i);
            }
        }
    }

}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    queue<int> q;
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            q.push(i);
            bfs(n, computers, visited, q);
            ++answer;
        }
    }
    return answer;
}