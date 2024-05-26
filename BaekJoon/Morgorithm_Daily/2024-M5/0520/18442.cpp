#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll V, P, L;
ll A[20];
ll ans = 1e17;
vector<ll> tmp, anstmp;

void calc(){
    ll ret = 0;
    rep(i, 0, V){
        ll mn = 1e17;
        rep(j, 0, P) mn = min(mn, min(abs(tmp[j]-A[i]), L-abs(tmp[j]-A[i])));
        ret += mn;
    }
    if(ret < ans){
        ans = ret;
        anstmp = tmp;
    }
}

void btr(ll idx){
    if(tmp.size() == P){calc(); return;}
    if(idx == V) return;
    tmp.push_back(A[idx]);
    btr(idx+1);
    tmp.pop_back();
    btr(idx+1);
}

void solve(){
    cin >> V >> P >> L;
    rep(i, 0, V) cin >> A[i];
    btr(0);
    cout << ans << "\n";
    for(auto i : anstmp) cout << i << " ";
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