#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, M;
vector<ll> A;
vector<pair<ll, bool>> sweep; // {pos, isEnd}

void solve(){
    cin >> N >> M;
    rep(i, 0, N){
        ll x; cin >> x;
        A.push_back(x);
    }
    rep(i, 0, M){
        ll s, e; cin >> s >> e;
        sweep.push_back({s, 0});
        sweep.push_back({e+1, 1});
    }
    sort(A.begin(), A.end());
    sort(sweep.begin(), sweep.end());
    vector<ll> pfsum, sfsum;
    pfsum.push_back(0);
    sfsum.push_back(0);
    for(auto x : A){
        pfsum.push_back(pfsum.back() + x);
    }
    for(ll i = N-1; i >= 0; i--){
        sfsum.push_back(sfsum.back() + A[i]);
    }
    ll mn = 0, mx = 0;
    ll pos = 0;
    ll cnt = 0;
    for(auto [x, isEnd] : sweep){
        mn += (x - pos) * pfsum[cnt];
        mx += (x - pos) * sfsum[cnt];
        if(isEnd) cnt--;
        else cnt++;
        pos = x;
    }
    cout << mn << ' ' << mx << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}