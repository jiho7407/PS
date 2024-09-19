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

ll N;
vector<tuple<ll, bool, ll>> A; // pos, isEnd, cost
vector<tuple<ll, ll, ll>> ans;

void solve(){
    cin >> N;
    rep(i, 0, N){
        ll S, E, C; cin >> S >> E >> C;
        A.push_back({S, 0, C});
        A.push_back({E, 1, C});
    }
    sort(A.begin(), A.end());

    ll stt, cnt = 0, mn = 1e9;
    for(auto [pos, isEnd, cost]: A){
        if(isEnd){
            cnt--;
            if(cnt == 0){
                ans.push_back({stt, pos, mn});
            }
        }
        else{
            cnt++;
            if(cnt == 1){
                stt = pos;
                mn = cost;
            }
            else mn = min(mn, cost);
        }
    }
    
    cout << ans.size() << '\n';
    for(auto [S, E, C]: ans) cout << S << ' ' << E << ' ' << C << '\n';
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