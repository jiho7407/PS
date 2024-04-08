#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int R, N, M, K;
vector<int> links[101];
int AM[101], BM[101];
bool visited[101];

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(int b : links[a]){
        if(BM[b] == -1 || dfs(BM[b])){
            AM[a] = b;
            BM[b] = a;
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> R;
    while(R--){
        cin >> N >> M >> K;
        double x, y;
        for(int i = 0; i<101; i++) links[i].clear();
        for(int i = 0; i<K; i++){
            cin >> x >> y;
            links[int(x)].push_back(int(y));
        }
        ll ans = 0;
        fill(AM, AM+101, -1);
        fill(BM, BM+101, -1);
        for(int i = 0; i<N; i++){
            fill(visited, visited+101, false);
            if(dfs(i)) ans++;
        }
        cout << ans << '\n';
    }
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}