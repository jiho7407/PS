#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#include <chrono>

#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
using namespace chrono;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll mxK = 1.7e7+1;
struct Xudyh{
    bool is_prime[mxK];
    ll mu[mxK], SF_DP[mxK];
    unordered_map<ll, ll> mp;

    void init(){
        // calc SF for K >= sqrt(N)
        fill(is_prime, is_prime+mxK, 1);
        fill(mu, mu+mxK, 1);
        fill(SF_DP, SF_DP+mxK, 0);
        mu[1] = 1;
        SF_DP[1] = 1;
        // cout << "init" << endl;
        rep(i, 2, mxK){
            if(is_prime[i]){
                mu[i] = -1;
                for(ll j = i*2; j<mxK; j+=i){
                    is_prime[j] = 0;
                    mu[j] *= -1;
                }
                ll I = i*i;
                for(ll j = I; j<mxK; j+=I){
                    mu[j] = 0;
                }
            }
            SF_DP[i] = SF_DP[i-1] + mu[i];
        }
        // cout << "init done" << endl;
        // rep(i, 1, 21) cout << mu[i] << ' ';
        // cout << '\n';
    }

    ll SF(ll N){
        if(N < mxK) return SF_DP[N];
        if(mp.find(N) != mp.end()) return mp[N];

        ll &ret = mp[N] = 1;
        for(ll i = 2, j; i<=N; i=j+1){
            ll ni = N/i;
            j = N/ni;
            ret -= SF(ni)*(j-i+1);
        }
        return ret;
    }
}Xudyh;

ll SFI(ll N){
    ll ret = 0;
    for(ll i = 1, j; i*i<=N; i=j+1){
        ll ni = N/(i*i);
        j = sqrt(N/ni);
        ret += (Xudyh.SF(j)-Xudyh.SF(i-1))*ni;
    }
    return ret;
}

void solve(){
    ll N; cin >> N;
    auto start = high_resolution_clock::now();
    Xudyh.init();

    ld pi = 3.14159265358979323846264338327950288419716939937510;
    ld md = (ld)N/(ld)6*pi*pi;

    ll sigma = 50000;
    // N = 950000000000000000일때 40190차이..
    // if(N < 1e17) sigma = 30000;

    ll ng = max((ll)0, (ll)md-sigma), ok = min((ll)1644934066848209910, (ll)md+sigma);
    while(ok-ng > 1){
        ll mid = (ok+ng)>>1;
        if(SFI(mid) < N) ng = mid;
        else ok = mid;
    }
    // cout << (ll)md << '\n';
    cout << ok << '\n';
    // cout << ((ll)md-ok) << '\n';

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds>(stop - start);
    // cout << "Time: " << duration.count() << "ms\n";
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