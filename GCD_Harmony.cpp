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

ll N;
vector<ll> links[5000];
ll V[5000];
ll DP[5000][500];

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll calc(ll cur, ll par, ll num){
    if(DP[cur][num] != -1) return DP[cur][num];
    ll &ret = DP[cur][num] = 0;
    if(num != V[cur]) ret += num;
    for(auto nxt: links[cur]){
        if(nxt == par) continue;
        ll val = 1e5;
        rep(nnum, 1, 500){
            if(gcd(num, nnum) == 1) continue;
            val = min(val, calc(nxt, cur, nnum)); 
        }
        ret += val;
    }
    return ret;
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> V[i];
    rep(i, 0, N-1){
        ll u, v; cin >> u >> v;
        u--, v--;
        links[u].push_back(v);
        links[v].push_back(u);
    }

    rep(i, 0, N) rep(j, 0, 500) DP[i][j] = -1;
    ll ans = 1e5;
    rep(i, 1, 500) ans = min(ans, calc(0, -1, i));
    cout << ans;
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}