#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx = 2010;
int N, M;
int Nlst[mx];
int link[mx][mx];
int Ncon[mx], Mcon[mx];
int Mvisit[mx];
int visitcnt = 1;

bool dfs(int n){
    if(Mvisit[n] == visitcnt) return false;

    Mvisit[n] = visitcnt;

    for(int m=1; m<=N; m++){
        if(link[n][m]){
            if(!Mcon[m] || dfs(Mcon[m])){
                Ncon[n] = m;
                Mcon[m] = n;
                return true;
            }
        }
    }
    return false;
}

int main(){
    fastio();
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        fill(link[i], link[i]+N+1, 0);
    }
    fill(Nlst, Nlst+N+1, 0);
    fill(Ncon, Ncon+N+1, 0);
    fill(Mcon, Mcon+N+1, 0);

    for(int _ = 0; _<N; _++){
        int i;
        char c;
        cin >> i >> c;
        if(c=='c'){
            Nlst[i] = 1;
        }
    }
    while(M--){
        int s, e;
        cin >> s >> e;
        link[s][e] = 1;
        link[e][s] = 1;
    }

    int MVC = 0; // 최소 버텍스 커버. 쾨닉의 정리 이용.
    
    for(int i = 1; i<=N; i++){
        if(!Nlst[i]) continue;
        visitcnt++;
        if(dfs(i)) MVC++;
    }
    cout << N-MVC;
    return 0;
}