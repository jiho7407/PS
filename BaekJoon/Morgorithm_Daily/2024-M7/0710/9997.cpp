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
string word[25];
vector<int> v1;
ll ans;

void dfs(int idx, int mask){
    if(idx == N){
        if(mask == (1 << 26) - 1) ans++;
        return;
    }
    dfs(idx+1, mask | v1[idx]);
    dfs(idx+1, mask);
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> word[i];
    rep(i, 0, N){
        int tmp = 0;
        for(auto c: word[i]) tmp |= 1 << (c - 'a');
        v1.push_back(tmp);
    }
    dfs(0, 0);
    cout << ans;
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