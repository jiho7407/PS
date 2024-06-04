#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, L;
vector<pair<ll, bool>> light; // {pos, isend};

void solve(){
    cin >> N >> L;
    rep(i, 0, N){
        ll x; cin >> x;
        light.push_back({x-L, 0});
        light.push_back({x+L, 1});
    }
    sort(light.begin(), light.end());
    ll ans = 0;
    ll cnt = 0;
    ll lastpos=0;
    for(auto [pos, isend]: light){
        if(isend){
            cnt--;
            if(cnt > 0){
                ans += pos - lastpos;
                lastpos = pos;
            }
        }
        else{
            cnt++;
            if(cnt == 2) lastpos = pos;
        }
        // cout << pos << ' ' << isend << ' ' << lastpos << ' ' << cnt << ' ' << ans << '\n';
    }
    cout << ans;
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