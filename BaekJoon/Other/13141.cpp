#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
int links[205][205];
int longlinks[205][205];

int solve(int a){
    int temp = 0;
    for(int i = 1; i<=N; i++){
        for(int j = 0; j<=N; j++){
            temp = max(temp, links[a][i]+links[a][j]+longlinks[i][j]);
            // cout << a << " " << i << " " << j << " " << links[a][i]+links[a][j]+longlinks[i][j] << "\n";
        }
    }
    return temp;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i<=N; i++){
        fill(links[i], links[i]+N+1, -1);
        fill(longlinks[i], longlinks[i]+N+1, 0);
    }
    for(int i = 0; i<M; i++){
        int S, E, L;
        cin >> S >> E >> L;
        if(links[S][E] == -1) links[S][E] = L;
        else links[S][E] = min(links[S][E], L);
        if(links[E][S] == -1) links[E][S] = L;
        else links[E][S] = min(links[E][S], L);

        if(longlinks[S][E] == -1) longlinks[S][E] = L;
        else longlinks[S][E] = max(longlinks[S][E], L);
        if(longlinks[E][S] == -1) longlinks[E][S] = L;
        else longlinks[E][S] = max(longlinks[E][S], L);
    }
    for(int k = 1; k<=N; k++){
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<=N; j++){
                if(links[i][k] == -1 || links[k][j] == -1) continue;
                if(links[i][j] == -1) links[i][j] = links[i][k]+links[k][j];
                else links[i][j] = min(links[i][j], links[i][k]+links[k][j]);
            }
        }
    }
    int ans = 10000000;
    for(int i = 1; i<=N; i++){
        links[i][i] = 0;
        ans = min(ans, solve(i));
    }
    float answer = float(ans)/2;
    if(answer==ans/2) cout << answer << ".0";
    else cout << answer;
}