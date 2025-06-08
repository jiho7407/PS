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

bool palin(ll N, ll base){
    vector<ll> v;
    while(N){
        v.push_back(N%base);
        N /= base;
    }
    for(int i = 0; i < v.size()/2; i++){
        if(v[i] != v[v.size()-1-i]) return false;
    }
    return true; 
}

void solve(){
    ll N; cin >> N;
    vector<ll> ans;
    for(ll base = 2; base*base <= N; base++){
        if(palin(N, base)) ans.push_back(base);
    }
    for(ll num = 1; num*num <= N; num++){
        if((N - num) % num == 0){
            ll base = (N - num) / num;
            if(num >= base) continue;
            ans.push_back(base);
        }
    }r
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    if(ans.size() == 0) cout << "*";
    else for(auto x:ans) cout << x << ' ';
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