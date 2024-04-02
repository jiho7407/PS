#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
string S, T, newS;
int a, b;
char coin[2];

bool dfs(int s, int used){
    if(s+used == N) return true;
    if(used < 2 && coin[used] == T[s+used]){
        if(dfs(s, used+1)) return true;
    }
    if(newS[s] == T[s+used]) return dfs(s+1, used);
    return false;
}

void solve(){
    cin >> N;
    cin >> S;
    cin >> T;
    cin >> a >> b;
    coin[0] = S[a]; coin[1] = S[b];
    newS = "";
    for(int i = 0; i<N; i++){
        if(i == a || i == b) continue;
        newS.push_back(S[i]);
    }
    if(dfs(0, 0)) cout << "YES";
    else cout << "NO";
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}