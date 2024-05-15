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

void solve(){
    int N; cin >> N;
    vector<int> v(N);
    rep(i, 0, N) cin >> v[i];
    vector<pii> ans;
    rep(i, 1, N+1){
        int idx = -1;
        rep(j, 0, N){
            if(v[j] == i){
                idx = j;
                break;
            }
        }
        while(idx > i-1){
            int len = idx - (i-1);
            if(len%2 == 0) len--;
            ans.push_back({idx-len, idx});
            rep(j, 0, (len+1)/2){
                swap(v[idx-j], v[idx-(len+1)/2-j]);
            }
            idx -= (len+1)/2;
        }
    }
    cout << ans.size() << '\n';
    for(auto p : ans){
        cout << p.first+1 << ' ' << p.second+1 << '\n';
    }
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}