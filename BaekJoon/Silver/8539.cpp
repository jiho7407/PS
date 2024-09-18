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
vector<pair<int, bool>> nets; // {x, isEnd};

void solve(){
    cin >> N;
    rep(i, 0, N){
        int a, b; cin >> a >> b;
        nets.push_back({a, 0});
        nets.push_back({b, 1});
    }
    sort(nets.begin(), nets.end());
    int ans = 0, cnt = 0;
    for(auto [x, isEnd]: nets){
        if(isEnd) cnt--;
        else cnt++;
        ans = max(ans, cnt);
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