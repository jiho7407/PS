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

ld T;
int N;
ll W[1000];
bool pos[1000001];

void solve(){
    cin >> T >> N;
    rep(i, 0, N) cin >> W[i];
    ll mn = 1e9, mx = 0;
    rep(i, 0, N) mn = min(mn, W[i]), mx = max(mx, W[i]);
    fill(pos, pos+1000001, true);
    rep(i, 0, N){
        ld X = W[i];
        int cnt = 1;
        rep(j, X/T+1, mx+1) pos[j] = false;
        while(1){
            if(T*(cnt+1) < cnt) break;
            if((ll)X%cnt) rep(j, X/(T*(cnt+1))+1, X/cnt+1) pos[j] = false;
            else rep(j, X/(T*(cnt+1))+1, X/cnt) pos[j] = false;
            cnt++;
        }
    }
    int ln = 0;
    rep(i, 0, mx+1) if(pos[i]) ln = i;
    int ans = 0;
    rep(i, 0, N){
        if(W[i]%ln) ans += W[i]/ln;
        else ans += W[i]/ln-1;
    }
    cout << ans << '\n';
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