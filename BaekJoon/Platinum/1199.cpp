#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int links[1000][1000];
int nxt[1000] = {0};

void dfs(int i){
    for(int &j = nxt[i]; j < N; j++){
        if(links[i][j]){
            links[i][j]--;
            links[j][i]--;
            dfs(j);
        }
    }
    cout << i+1 << ' ';
    return;
}

void solve(){
    cin >> N;
    rep(i, 0, N) rep(j, 0, N){
        cin >> links[i][j];
    }

    rep(i, 0, N){
        int cnt = 0;
        rep(j, 0, N) cnt += links[i][j];
        if(cnt % 2){
            cout << -1;
            return;
        }
    }
    
    dfs(0);
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