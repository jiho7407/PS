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

void solve(){
    ll N; cin >> N;
    vector<ll> v(N);
    rep(i, 0, N) cin >> v[i];

    vector<pii> v2;
    v2.push_back({v[0], 1});
    rep(i, 1, N){
        if(v[i] == v2.back().first) v2.back().second++;
        else v2.push_back({v[i], 1});
    }

    ll M = v2.size();
    vector<ll> lft(M), rgt(M);

    ll mx = 0, cnt = 0;
    rep(i, 0, M){
        if(v2[i].first > mx){
            lft[i] = cnt;
            cnt += v2[i].second;
            mx = v2[i].first;
        }
        else{
            lft[i] = 0;
            mx = v2[i].first;
            cnt = v2[i].second;
        }
    }

    mx = 0, cnt = 0;
    for(ll i = M-1; i >= 0; i--){
        if(v2[i].first > mx){
            rgt[i] = cnt;
            cnt += v2[i].second;
            mx = v2[i].first;
        }
        else{
            rgt[i] = 0;
            mx = v2[i].first;
            cnt = v2[i].second;
        }
    }

    ll ans = 0;
    rep(i, 0, M){
        ll a = lft[i], b = v2[i].second, c = rgt[i];
        ans += a * (b+c);
        ans += b * ((c + 1) + (c + b)) / 2;
    }
    cout << ans << "\n";
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