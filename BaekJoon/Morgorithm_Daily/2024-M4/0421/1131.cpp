#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 4'000'010;
ll DP[mxN];
bool visited[mxN];
ll A, B, K;

ll pow(ll a, ll x){
    ll ret = 1;
    while(x){
        if(x%2) ret *= a;
        a *= a;
        x /= 2;
    }
    return ret;
}

ll SK(ll x){
    ll ret = 0;
    while(x){
        ret += pow(x%10, K);
        x /= 10;
    }
    return ret;
}

ll dfs(ll x){
    if(DP[x] != -1) return DP[x];
    if(visited[x]){
        ll temp = x, mn = x;
        temp = SK(temp);
        while(temp != x){
            mn = min(mn, temp);
            temp = SK(temp);
        }
        return DP[x] = mn;
    }
    visited[x] = true;
    DP[x] = min(x, dfs(SK(x)));
    return DP[x];
}

void solve(){
    cin >> A >> B >> K;
    fill(DP, DP+mxN, -1);
    fill(visited, visited+mxN, false);
    ll ans = 0;
    rep(i, A, B+1) ans += dfs(i);
    cout << ans << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}