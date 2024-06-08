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

int N;

ll calc(int cnt){
    return (ll)cnt*(cnt-1)/2;
}

void solve(){
    cin >> N;
    int a; cin >> a;
    int state = 0; // 0: same, 1: up, 2: down
    ll ans = 0, cnt = 1;
    rep(i, 1, N){
        int b; cin >> b;
        if(a<b){
            if(state == 0){
                cnt = 2;
            }
            else if(state == 1){
                ans += calc(cnt);
                cnt = 2;
            }
            else{
                cnt++;
            }
            state = 1;
        }
        else if(a>b){
            if(state==0) cnt = 2;
            else if(state == 1) cnt++;
            else{
                ans += calc(cnt);
                cnt = 2;
            }
            state = 2;
        }
        else{
            ans += calc(cnt);
            cnt = 1;
        }
        a = b;
    }
    ans += calc(cnt);
    cout << ans << '\n';
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