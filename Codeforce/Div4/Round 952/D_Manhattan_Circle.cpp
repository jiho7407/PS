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

string board[2000000];

void solve(){
    int N, M; cin >> N >> M;
    rep(i, 0, N) cin >> board[i];
    int mx = 0;
    pii ans;
    rep(i, 0, N){
        int cnt = 0;
        rep(j, 0, M) if(board[i][j] == '#') cnt++;
        if(mx > cnt) break;
        if(mx < cnt){
            int tmp = 0;
            rep(j, 0, M){
                if(board[i][j] == '#') tmp++;
                if(tmp == (cnt+1)/2){ ans = {i, j}; break; }
            }
            mx = cnt;
        }
        // cout << cnt << ' ' << ans.first << ' ' << ans.second << '\n';
    }
    cout << ans.first+1 << ' ' << ans.second+1 << '\n';
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