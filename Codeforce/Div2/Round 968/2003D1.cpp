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

int mexex(set<int> &s){
    int i = 0;
    while(s.count(i)) i++;
    i++;
    while(s.count(i)) i++;
    return i;
}

void solve(){
    ll N, M;
    cin >> N >> M;
    ll mx = -1;
    rep(i, 0, N){
        set<int> s;
        int cnt; cin >> cnt;
        while(cnt--){
            int x; cin >> x;
            s.insert(x);
        }
        mx = max(mx, (ll)mexex(s));
    }
    
    if(M <= mx){
        cout << (ll)mx*(M+1) << '\n';
    }
    else{
        ll ret = 0;
        ret += (ll)mx*(mx+1);
        ret += (ll)(M-mx)*(M+mx+1)/2;
        cout << ret << '\n';
    }
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