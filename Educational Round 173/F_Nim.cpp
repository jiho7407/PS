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

// 나머지 연산
const ll MOD = 998244353;
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

pair<ll, ll> DP[52][64][2];

void merge(pair<ll, ll> &A, ll mx, ll cnt){
    if(A.first < mx) A = {mx, cnt};
    else if(A.first == mx) A.second = addmod(A.second, cnt, MOD);
    return;
}

void solve(){
    int N, Q; cin >> N >> Q;
    vector<int> arr(N);
    vector<vector<int>> cnts(N+1, vector<int>(51));
    rep(i, 0, N){
        cin >> arr[i];
        rep(j, 0, 51){
            cnts[i+1][j] = cnts[i][j] + (arr[i] == j);
        }
    }
    while(Q--){
        int L, R; cin >> L >> R;
        fill_n(&DP[0][0][0], 52*64*2, pll{-1, -1});
        DP[0][0][0] = {0, 1};
        rep(i, 0, 51){
            ll c = cnts[R][i] - cnts[L-1][i];
            ll c2 = c * (c-1) / 2;
            rep(val, 0, 64) rep(f, 0, 2){
                if(DP[i][val][f].second < 0) continue;
                merge(DP[i+1][val][f], DP[i][val][f].first + c, DP[i][val][f].second);
                if(c) merge(DP[i+1][val^i][1], DP[i][val][f].first + c-1, mulmod(DP[i][val][f].second, c, MOD));
                if(c2) merge(DP[i+1][val][1], DP[i][val][f].first + c - 2, mulmod(DP[i][val][f].second, c2, MOD));
            }
        }
        auto ans = DP[51][0][1];
        if(ans.first == -1) cout << -1 << '\n';
        else cout << ans.first << ' ' << ans.second << '\n';
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