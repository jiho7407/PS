#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
int R[101], W[2001];
int park[101];
queue<int> Q;

int main(){
    fastio();
    cin >> N >> M;
    for(int i = 1; i<=N; i++){
        cin >> R[i];
    }
    for(int i = 1; i<=M; i++){
        cin >> W[i];
    }

    fill(park, park+101, 0);
    int ans = 0;
    for(int i = 1; i<=2*M; i++){
        int cmd;
        cin >> cmd;
        if(cmd>0){
            int goal = -1;
            for(int j = 1; j<=N; j++){
                if(park[j] == 0){
                    goal = j;
                    break;
                }
            }
            if(goal == -1) Q.push(cmd);
            else park[goal] = cmd;
        }
        else{
            cmd *= -1;
            int goal = -1;
            for(int j = 1; j<=N; j++){
                if(park[j] == cmd){
                    goal = j;
                    break;
                }
            }
            ans += R[goal]*W[park[goal]];
            park[goal] = 0;
            if(!Q.empty()){
                park[goal] = Q.front(); Q.pop();
            }
        }
    }
    cout << ans;
    return 0;
}