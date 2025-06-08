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
    int K; cin >> K;
    set<int> s;
    while(K--){
        int a; cin >> a;
        s.insert(a);
    }
    int N; cin >> N;
    int mx = 24*60, ans = -1, cnt = 0;
    while(N--){
        int a, h, m; cin >> a >> h >> m;
        if(s.find(a) == s.end()) continue;
        if(h == -1 && m == -1) continue;
        int t = h*60+m;
        if(t <= 6*60) cnt++;
        if(t < mx){
            mx = t;
            ans = a;
        }
    }
    cout << ans << ' ' << cnt << '\n';
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