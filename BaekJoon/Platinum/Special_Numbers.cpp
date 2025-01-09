#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int, int> tii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll K;
string L, R;
const ll MOD = 1e9+7;

ll gcd(ll a, ll b){
    return b ? gcd(b, a%b) : a;
}

ll dv(ll k, ll n){
    return (k / gcd(k, n));
}

ll calc(string S, bool isL = false){
    vector<int> digits;
    for(auto c : S){
        digits.push_back(c-'0');
    }
    int n = digits.size();

    map<tuple<bool, bool, ll>, ll> DP; // (tight, LeadingZero, state)
    rep(i, 0, digits[0]+1){
        tuple<bool, bool, ll> state = {i == digits[0], i == 0, (i==0) ? K : dv(K, i)};
        DP[state]++;
    }

    rep(i, 1, n){
        map<tuple<bool, bool, ll>, ll> DPN;
        for(auto [state, cnt]: DP){
            auto [tight, leadingZero, X] = state;
            rep(d, 0, 10){
                if(tight && digits[i]<d) break;
                bool nT = tight && digits[i] == d;
                bool nL = leadingZero && d == 0;
                ll nX = nL ? X : dv(X, d);
                tuple<bool, bool, ll> nState = {nT, nL, nX};
                DPN[nState] += cnt;
                DPN[nState] %= MOD;
            }
        }
        DP = DPN;
    }

    ll ans = 0;
    rep(i, 0, 2) ans += DP[{i, 0, 1}];

    if(isL){
        ll X = K;
        bool flag = false;
        for(auto d : digits){
            X = dv(X, d);
            if(d == 0) flag = true;
        }
        if(X == 1 || flag) ans--;
    }
    return ans % MOD;
}

void solve(){
    cin >> K >> L >> R;    
    cout << (calc(R) - calc(L, true) + MOD)%MOD << endl;
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