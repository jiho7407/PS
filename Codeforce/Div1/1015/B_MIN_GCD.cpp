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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve(){
    int N; cin >> N;
    vector<ll> v(N), Sfg(N);
    rep(i, 0, N) cin >> v[i];
    sort(v.begin(), v.end());
    Sfg[N-1] = v[N-1];
    for(int i = N-2; i >= 0; i--) Sfg[i] = gcd(Sfg[i+1], v[i]);

    bool flag = false;
    if(v[0] == v[1]) flag = true;
    else{
        vector<ll> tmp;
        rep(i, 1, N){
            if(v[i]%v[0]) continue;
            tmp.push_back(v[i]/v[0]);
        }
        if(tmp.size() >= 2){
            ll GCD = tmp[0];
            for(auto x : tmp) GCD = gcd(GCD, x);
            if(GCD == 1) flag = true;
        }
    }

    if(flag) cout << "Yes\n";
    else cout << "No\n";
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