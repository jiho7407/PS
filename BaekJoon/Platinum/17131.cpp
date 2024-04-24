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

struct Fenwick{
    vector<ll> tree;
    Fenwick(int n){
        tree.resize(n+1);
    }
    void update(int idx, ll diff){
        while(idx < tree.size()){
            tree[idx] += diff;
            idx += (idx & -idx);
        }
    }
    ll query(int idx){
        ll ret = 0;
        while(idx > 0){
            ret += tree[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }
};

const ll mod = 1e9 + 7;
vector<pii> star;

bool cmp(pii a, pii b){
    return a.second > b.second;
}

void solve(){
    ll N; cin >> N;
    rep(i, 0, N) {
        ll x, y; cin >> x >> y;
        x += 200001;
        y += 200001;
        star.push_back({x, y});
    }
    sort(star.begin(), star.end(), cmp);
    Fenwick FT(400002);
    ll ans = 0;
    ll lasty = -1;
    vector<ll> tempx;
    for(auto [x, y] : star){
        if(lasty != y){
            for(auto tx : tempx){
                FT.update(tx, 1);
            }
            tempx.clear();
            lasty = y;
        }
        ans += FT.query(x-1) * (FT.query(400002) - FT.query(x));
        ans %= mod;
        tempx.push_back(x);
    }
    cout << ans;
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