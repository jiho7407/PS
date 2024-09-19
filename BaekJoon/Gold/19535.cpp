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
vector<int> links[300000];

ll Dcnt = 0, Gcnt = 0;

ll NC3(ll n){
    return n*(n-1)/2*(n-2)/3;
}

void dfs(int c, int p){
    Gcnt += NC3(links[c].size());
    for(auto nxt: links[c]){
        if(nxt == p) continue;
        Dcnt += 1LL * (links[c].size()-1) * (links[nxt].size()-1);
        dfs(nxt, c);
    }
}

void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    dfs(0, -1);
    Gcnt *= 3;
    if(Dcnt > Gcnt) cout << "D";
    else if(Dcnt < Gcnt) cout << "G";
    else cout << "DUDUDUNGA";
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