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

set<pii> visited;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int K;

int calc(pii p){
    auto [x, y] = p;
    return (x+y-1)*(x+y-2)/2 + x;
}

bool cmp(pair<int, pii> a, pair<int, pii> b){
    return calc(a.second) < calc(b.second);
}

void solve(){
    cin >> K;
    pii cur = {1, 1};
    visited.insert(cur);
    while(K--){
        vector<pair<int, pii>> pos;
        for(int i = 0; i < 8; i++){
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if(nx < 1 || ny < 1) continue;
            if(visited.find({nx, ny}) == visited.end()){
                pos.push_back({calc({nx, ny}), {nx, ny}});
            }
        }
        sort(pos.begin(), pos.end(), cmp);
        cur = pos[0].second;
        visited.insert(cur);
    }
    cout << calc(cur) << '\n';
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