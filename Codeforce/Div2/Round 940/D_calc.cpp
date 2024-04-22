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

int N;
vector<ll> A;
vector<ll> XOR;
vector<tuple<int, int, int>> ans;

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
    return get<1>(a) < get<1>(b);
}

void solve(){
    cin >> N;
    A.resize(N+1);
    XOR.resize(N+1);
    rep(i, 1, N+1) cin >> A[i];
    XOR[0] = 0;
    rep(i, 1, N+1) XOR[i] = XOR[i-1] ^ A[i];
    rep(i, 1, N+1){
        rep(j, i, N+1){
            ll unit = XOR[i-1]^XOR[j];
            rep(k, i, j+1){
                if((unit^A[k]) > unit) ans.push_back({i-1, k-1, j-1});
            }
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << "\n";
    for(auto x : ans){
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";
    }
    ans.clear();
    cout << "\n";
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