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

ll N, K, P;
vector<ll> fact, invfact, pow2;
ll DP[501][501];

ll modpow(ll a, ll b, ll mod){
    ll ret = 1;
    while(b){
        if(b&1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void init(){
    fact.resize(K+1);
    fact[0] = 1;
    rep(i, 1, K+1) fact[i] = fact[i-1] * i % P;

    invfact.resize(K+1);
    invfact[K] = modpow(fact[K], P-2, P);
    for(int i = K-1; i >= 0; i--) invfact[i] = invfact[i+1] * (i+1) % P;

    pow2.resize(N+1);
    pow2[0] = 1;
    rep(i, 1, N+1) pow2[i] = pow2[i-1] * 2 % P;

    fill_n(&DP[0][0], 501*501, 0);
    rep(i, 0, K+1) DP[1][i] = 1;
}

void solve(){
    cin >> N >> K >> P;
    init();
    rep(i, 1, N){
        vector<ll> tmp(K+1); // tmp[a] = comb(a + (2^i - 2), a);
        tmp[0] = 1;
        rep(j, 1, K+1){
            tmp[j] = tmp[j-1] * (j + (pow2[i] - 2) + P) % P;
        }
        rep(j, 0, K+1){
            tmp[j] *= invfact[j];
            tmp[j] %= P;
        }

        rep(j, 0, K+1){
            rep(k, 0, j){
                // 오른쪽 아래 서브트리에 채우는 과정
                if(j+k > K) break;
                DP[i+1][j+k] += DP[i][j] * tmp[k] % P;
                DP[i+1][j+k] %= P;
            }
        }

        rep(j, 1, K+1){
            // 루트에 채우는 과정
            DP[i+1][j] += DP[i+1][j-1];
            DP[i+1][j] %= P;
        }
    }
    cout << DP[N][K]*pow2[N-1]%P << '\n';
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