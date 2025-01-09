#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <bit>
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

const int mxN = 7000;
int N;
const ll MOD = 1e9+7;
vector<tuple<int, int, int, int>> lines;
bitset<mxN> adj[mxN];

bool isInter(tuple<int, int, int, int> &A, tuple<int, int, int, int> &B){
    auto [a, b, c, d] = A;
    auto [e, f, g, h] = B;
    if(a == c && e == g) return false;
    if(b == d && f == h) return false;
    if(a == c && e <= a && a <= g && b <= f && f <= d) return true;
    if(b == d && f <= b && b <= h && a <= e && e <= c) return true;
    return false;
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(a > c) swap(a, c);
        if(b > d) swap(b, d);
        lines.push_back({a, b, c, d});
    }

    rep(i, 0, N){
        rep(j, i+1, N){
            if(isInter(lines[i], lines[j])){
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }

    int ans = 0;
    rep(i, 0, N){
        bitset<mxN> visited = 0;
        visited.set();

        queue<int> Q;
        Q.push(i);
        visited[i] = 0;
        int dist = 1;

        while(!Q.empty()){
            int sz = Q.size(), jsum = 0;

            bitset<mxN> ret = 0;
            while(sz--){
                int cur = Q.front(); Q.pop();
                ret |= adj[cur];
            }
            ret &= visited;
            for(int pos = ret._Find_first(); pos < mxN; pos = ret._Find_next(pos)){
                visited[pos] = ret[pos] = 0;
                Q.push(pos);
                jsum += pos+1;
            }

            ans += ((i+1)*dist%MOD*jsum%MOD)%MOD;
            if(ans >= MOD) ans -= MOD;
            dist++;
        }
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