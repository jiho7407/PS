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
vector<int> pos[1001], child[1001];

void dfs(int cur){
    for(auto nxt: pos[cur]){
        cout << "? " << cur << ' ' << nxt << '\n';
        cout.flush();
        int x; cin >> x;
        if(x == cur){
            child[cur].push_back(nxt);
        }
        else{
            pos[x].push_back(nxt);
        }
    }
    for(auto nxt: child[cur]){
        dfs(nxt);
    }
}

void solve(){
    cin >> N;
    rep(i, 0, 1001){
        pos[i].clear();
        child[i].clear();
    }

    rep(i, 2, N+1) pos[1].push_back(i);
    dfs(1);

    cout << "! ";
    rep(i, 1, N+1){
        for(auto nxt: child[i]){
            cout << i << ' ' << nxt << ' ';
        }
    }
    cout << '\n';
    cout.flush();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}