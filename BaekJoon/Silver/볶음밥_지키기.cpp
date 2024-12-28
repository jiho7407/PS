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

void solve(){
    int N, R; cin >> N >> R;
    vector<pii> rices(N);
    rep(i, 0, N){ 
        cin >> rices[i].first >> rices[i].second;
    }

    pii ans;
    int mx = 0;
    rep(x, -100, 101) rep(y, -100, 101){
        int cnt = 0;
        rep(i, 0, N){
            ll dist = 0;
            dist += (rices[i].first - x) * (rices[i].first - x);
            dist += (rices[i].second - y) * (rices[i].second - y);
            if(dist <= R*R) cnt++;
        }
        if(cnt > mx){
            mx = cnt;
            ans = make_pair(x, y);
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
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

