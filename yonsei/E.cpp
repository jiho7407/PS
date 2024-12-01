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

// 나머지 연산
ll addmod(ll a, ll b, ll mod){
   return (a%mod + b%mod)%mod;
}

ll submod(ll a, ll b, ll mod){
   return (a%mod - b%mod + mod)%mod;
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

ll invmod(ll a, ll mod){
   return powmod(a, mod-2, mod);
}

ll divmod(ll a, ll b, ll mod){
   return mulmod(a, invmod(b, mod), mod);
}

ll N, M, K, X;
ll door[200000];
vector<pll> links[200000];
ll dist[200000];

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, M){
        ll a, b, c; cin >> a >> b >> c;
        a--; b--;
        links[a].push_back({b, c});
        links[b].push_back({a, c});
    }
    cin >> X;
    rep(i, 0, X) cin >> door[i];
    rep(i, 0, X) door[i]--;

    dist[0] = 0;
    rep(i, 1, N) dist[i] = 1e18;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [cc, cur] = pq.top(); pq.pop();
        if(dist[cur] < cc) continue;

        for(auto [nxt, cost]: links[cur]){
            ll nc = cc + cost;
            if(dist[nxt] > nc){
                dist[nxt] = nc;
                pq.push({nc, nxt});
            }
        }
    }

    ll ans = 1e18;
    rep(i, 0, X){
        ll block = dist[door[i]] / K;
        // cout << dist[door[i]] << ' ' << block << ' ' << block%X << ' ' << (block+submod(i, block%X, X))*K << '\n';
        if(block % X == i) ans = min(ans, dist[door[i]]);
        else ans = min(ans, (block+submod(i, block%X, X))*K);
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