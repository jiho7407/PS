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

int N, M;
int cnt[200000];

int par[200000];
vector<int> group[200000];

int find(int x){
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    if(x>y) swap(x, y);
    par[y] = x;
}

void solve(){
    cin >> N >> M;
    fill(cnt, cnt+N, 0);
    rep(i, 0, N) par[i] = i;
    rep(i, 0, M){
        int a, b; cin >> a >> b; a--, b--;
        merge(a, b);
        cnt[a]++; cnt[b]++;
    }
    // rep(i, 0, N) cout << find(i) << ' ';
    // cout << '\n';
    rep(i, 0, N){
        if(cnt[find(i)] == 0) continue;
        group[find(i)].push_back(i);
    }
    int ans = 0;
    rep(i, 0, N){
        if(group[i].empty()) continue;
        int odd = 0;
        for(auto x: group[i]) odd += cnt[x]%2;
        ans += 1 + (odd-1)/2;
    }
    cout << ans << '\n';
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