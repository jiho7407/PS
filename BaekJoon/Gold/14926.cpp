#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
bool visited[500][500];
int ocnt = 0;

void dfs(int cur){
    cout << 'a' << cur << ' ';
    if(cur == 1) ocnt++;
    rep(i, 1, N+1){
        if(cur == i) continue;
        if(visited[cur][i] || visited[i][cur]) continue;
        if(i == 1 && ocnt == N/2) continue;
        visited[cur][i] = visited[i][cur] = true;
        dfs(i);
        return;
    }
}

void solve(){
    cin >> N;
    fill_n(&visited[0][0], 500*500, false);
    dfs(1);
    cout << "a1";
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}