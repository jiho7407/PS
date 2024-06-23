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

ll N;
string S, T;

struct SegmentTree{
    ll sz;
    vector<ll> tree;

    void init(ll N){
        sz = 1;
        while(sz < N) sz *= 2;
        tree.resize(2*sz, 0);
    }

    void update(ll idx){
        idx += sz;
        tree[idx] = 1;
        while(idx > 1){
            idx >>= 1;
            tree[idx] = tree[2*idx] + tree[2*idx+1];
        }
    }

    ll query(ll s, ll e){
        ll ret = 0;
        s += sz;
        e += sz;
        while(s < e){
            if(s%2) ret += tree[s++];
            if(e%2) ret += tree[--e];
            s >>= 1;
            e >>= 1;
        }
        return ret;
    }
}ST;

deque<ll> alp[26];

void solve(){
    cin >> N >> S >> T;
    rep(i, 0, N) alp[S[i]-'A'].push_back(i);
    
    ST.init(N);
    ll ans = 0;
    rep(i, 0, N){
        int cmd = T[i]-'A';
        int idx = alp[cmd].front(); alp[cmd].pop_front();
        ans += ST.query(idx+1, N);
        ST.update(idx);
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