#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll p = 127, mod = 2000007;
// const ll p = 37, mod = 1'000'000'000'039;
int N;  
string S;

bool check(int m){
    // cout << m << endl;
    ll hash = 0;
    rep(i, 0, m) hash = (hash*p + S[i]) % mod;
    unordered_map<ll, int> mp;
    mp[hash] = 0;
    ll pm = 1;
    rep(i, 0, m-1) pm = (pm*p) % mod;
    rep(i, 1, N-m+1){
        hash = (hash - S[i-1]*pm) % mod;
        hash = (hash + mod) % mod;
        hash = (hash*p + S[i+m-1]) % mod;
        if(mp.find(hash) != mp.end()){
            if(mp.find(hash)->second + m <= i && S.substr(mp.find(hash)->second, m) == S.substr(i, m)) return true;
        }
        else mp[hash] = i;
    }
    return false;
}

void solve(){
    cin >> S; N = S.size();
    int ok = 0, ng = N;
    while(ng-ok>1){
        int mid = (ok+ng)/2;    
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    if(ok) cout << ok;
    else cout << -1;
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