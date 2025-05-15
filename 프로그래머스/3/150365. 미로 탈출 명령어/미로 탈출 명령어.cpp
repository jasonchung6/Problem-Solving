#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define pii pair<int, int>
//dlru dxdy
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
int N, M, R, C, K;
string ANS;
char dlru[4] = {'d', 'l', 'r', 'u'};

int calc_dis(int x, int y){
    return abs(x-R) + abs(y-C);
}

bool dfs(int x, int y) {
    //int vx, vy;
    if(ANS.size() == K){
        if(x == R && y == C){
            return true;
        }
        else{
            return false;
        }
    }
    
    if(K - ANS.size() < calc_dis(x,y)){
        return false;
    }

    for(int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 1 || ny < 1 || nx > N || ny > M){
            continue;
        }
        ANS.push_back(dlru[i]);
        if(dfs(nx, ny)){
            return true;
        }
        ANS.pop_back();
    }
    return false;
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    //string answer = "";
    int dis = abs(x-r) + abs(y-c);
    if((k - dis) < 0 || (k - dis) % 2 == 1){
        return "impossible";
    }
    N = n;
    M = m;
    R = r;
    C = c;
    K = k;
    dfs(x, y);
    return ANS;
}