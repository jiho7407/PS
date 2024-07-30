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

// 유파
// 분리집합
struct UnionFind{
    vector<int> par, cnt;
    int group;

    void init(int N){
        par.resize(N);
        cnt.resize(N);
        rep(i, 0, N){
            par[i] = i;
            cnt[i] = 1;
        }
        group = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
        group--;
    }
}UF;

// 나머지 연산
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

ll N, M;
const ll mod = 1e9+7;
vector<pii> edges;

void solve(){
    cin >> N >> M;
    rep(i, 0, M){
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    ll ans = 0;
    UF.init(N);
    for(int i = M-1; i >= 0; i--){
        auto [a, b] = edges[i];
        if(UF.find(a) == UF.find(0) && UF.find(b) == UF.find(N-1)){
            ans = addmod(ans, powmod(3, i, mod), mod);
            continue;
        }

        swap(a, b);
        if(UF.find(a) == UF.find(0) && UF.find(b) == UF.find(N-1)){
            ans = addmod(ans, powmod(3, i, mod), mod);
            continue;
        }
        
        UF.merge(a, b);
    }
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