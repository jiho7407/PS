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

struct Fenwick{
    vector<ll> tree;
    Fenwick(int n){
        tree.resize(n+1);
    }
    void update(int idx, ll diff){
        if(idx > 300000) return;
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

ll addmod(ll a, ll b, ll mod){
    return (a%mod + b%mod)%mod;
}

ll mulmod(ll a, ll b, ll mod){
    return (a%mod * b%mod)%mod;
}

ll powmod(ll a, ll b, ll mod){
    ll res = 1;
    while(b){
        if(b&1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}

const int mod = 1e9+7;
int N;
Fenwick FT(300000);
ll ans[300000];
multiset<int> st;
vector<ll> A;
vector<pair<int, pll>> query;

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll x; cin >> x;
        st.insert(x);
        FT.update(x, 1);
    }
    int Q; cin >> Q;
    rep(i, 0, Q){
        ll X, K; cin >> X >> K; K--;
        query.push_back({i, {X, K}});
    }

    sort(query.begin(), query.end(), [&](pair<int, pll> a, pair<int, pll> b){
        return a.second.first < b.second.first;
    });

    int qidx = 0;
    int cnt = 0;
    while(1){
        if(*st.begin()*2 > *st.rbegin()) break;
        while(query[qidx].second.first == cnt){
            int K = query[qidx].second.second;
            int ok = 300000, ng = 0;
            while(ok-ng > 1){
                int mid = (ok+ng)/2;
                if(FT.query(mid) > K) ok = mid;
                else ng = mid;
            }
            ans[query[qidx].first] = ok;
            qidx++;
        }
        FT.update(*st.begin()*2, 1);
        st.insert(*st.begin()*2);
        FT.update(*st.begin(), -1);
        st.erase(st.begin());
        cnt++;
    }
    
    // vector에 st값 넣기
    for(auto it = st.begin(); it != st.end(); it++){
        A.push_back(*it);
    }

    rep(i, qidx, Q){
        auto [idx, XK] = query[i];
        auto [X, K] = XK;
        X -= cnt;
        // cout << idx << ' ' << X << ' ' << K << '\n';
        K += X;
        ans[idx] = mulmod(A[K%N], powmod(2, K/N, mod), mod);
    }

    rep(i, 0, Q){
        cout << ans[i] << '\n';
    }
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