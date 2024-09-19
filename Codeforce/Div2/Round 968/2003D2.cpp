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

pll mexex(set<ll> &s){
    pll ret = {0, 0};
    ll i = 0;
    while(s.count(i)) i++;
    ret.first = i;
    i++;
    while(s.count(i)) i++;
    ret.second = i;
    return ret;
}

const ll mxN = 2e5+10;
vector<pll> mexs;
vector<ll> links[200010];

ll normax = 0;
ll nxt[mxN];
ll dfs(ll cur){
    ll &ret = nxt[cur];
    if(ret != -1) return ret;

    ret = cur;
    for(auto n: links[cur]){
        ret = max(ret, dfs(n));
    }
    if(links[cur].size() >= 2) normax = max(normax, ret);
    return ret;
}

void solve(){
    ll N, M;
    cin >> N >> M;
    normax = 0;
    ll mx = -1;
    rep(i, 0, N){
        set<ll> s;
        ll cnt; cin >> cnt;
        while(cnt--){
            ll x; cin >> x;
            s.insert(x);
        }
        pll ret = mexex(s);
        mexs.push_back(ret);
        mx = max(mx, (ll)ret.second);
        links[ret.first].push_back(ret.second);
        normax = max(normax, ret.first);
    }

    fill(nxt, nxt+mx+1, -1);
    rep(i, 0, mx+1) if(nxt[i] == -1) dfs(i);
    
    // rep(i, 0, mx+1) cout << nxt[i] << ' ';
    // cout << '\n';
    // cout << normax << '\n';
    if(M <= mx){
        ll ret = 0;
        rep(i, 0, M+1) ret += max(nxt[i], normax);
        cout << ret << '\n';
    }
    else{
        ll ret = 0;
        rep(i, 0, mx+1) ret += max(nxt[i], normax);
        ret += (ll)(M-mx)*(M+mx+1)/2;
        cout << ret << '\n';
    }

    rep(i, 0, mx+1) links[i].clear();
    mexs.clear();
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