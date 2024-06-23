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

int N;
int huru[200001][10];

bool check(int s, int e){
    int cnt = 0; 
    rep(i, 0, 10){
        if(huru[e][i] - huru[s][i] > 0) cnt++;
    }
    return cnt <= 2;
}

void solve(){
    cin >> N;
    fill_n(&huru[0][0], 200001*10, 0);
    rep(i, 1, N+1){
        int a; cin >> a;
        rep(j, 0, 10) huru[i][j] = huru[i-1][j];
        huru[i][a]++;
    }
    int ans = 0;
    rep(i, 0, N+1){
        int ok = i, ng = N+1;
        while(ng - ok > 1){
            int mid = (ok + ng) / 2;
            if(check(i, mid)) ok = mid;
            else ng = mid;
        }
        ans = max(ans, ok - i);
    }
    cout << ans;
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