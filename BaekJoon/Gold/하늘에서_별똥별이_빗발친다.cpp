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
    int N, M, L, K; cin >> N >> M >> L >> K;
    vector<pii> stars;
    vector<int> xs, ys;
    rep(i, 0, K){
        int x, y; cin >> x >> y;
        stars.push_back({x, y});
        xs.push_back(x);
        ys.push_back(y);
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());
    
    int ans = 0;
    for(auto x: xs) for(auto y: ys){
        int cnt = 0;
        for(auto star: stars){
            if(star.first < x || star.first > x+L) continue;
            if(star.second < y || star.second > y+L) continue;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << K - ans;
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