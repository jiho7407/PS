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

ll N, M;
vector<ll> A;
ll MOD = 1e9+7;

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

void solve(){
    cin >> N >> M;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];

    if(M == 1){
        cout << N+1 << ' ' << 1;
        return;
    }

    rep(ln, 1, N+2){
        set<ll> st;
        ll hsh = 0;
        rep(i, 0, ln){
            hsh = addmod(mulmod(hsh, M, MOD), A[i], MOD);
        }
        st.insert(hsh);
        rep(i, ln, N){
            hsh = submod(hsh, mulmod(A[i-ln], powmod(M, ln-1, MOD), MOD), MOD);
            hsh = addmod(mulmod(hsh, M, MOD), A[i], MOD);
            st.insert(hsh);
        }
        
        ll cnt = powmod(M, ln, MOD);

        if(st.size() < cnt){
            cout << ln << ' ' << cnt - st.size() << '\n';
            return;
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