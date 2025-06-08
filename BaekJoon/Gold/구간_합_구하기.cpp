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

ll N, M, K;

struct mpST{
    ll MX;
    unordered_map<ll, ll> mp;
    
    ll pull(ll a, ll b){
        return a+b;
    }

    ll query(ll idx){
        if(mp.find(idx) == mp.end()) return 0;
        return mp[idx];
    }

    void update(ll i, ll x){
        i += MX;
        ll diff = x - query(i);
        mp[i] += diff;
        while(i >>= 1){
            mp[i] = pull(query(i << 1), query(i << 1 | 1));
        }
    }

    ll query(ll L, ll R){
        ll ret = 0;
        L += MX; R += MX;
        while(L <= R){
            if(L & 1) ret = pull(ret, query(L++));
            if(~R & 1) ret = pull(ret, query(R--));
            L >>= 1; R >>= 1;
        }
        return ret;
    }
}ST;

void solve(){
    cin >> N >> M >> K;
    ST.MX = N;
    M += K;
    rep(i, 0, N){
        ll x; cin >> x;
        ST.update(i, x);
    }
    while(M--){
        ll a, b, c; cin >> a >> b >> c;
        if(a == 1){
            ST.update(b-1, c);
        }else{
            cout << ST.query(b-1, c-1) << '\n';
        }
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