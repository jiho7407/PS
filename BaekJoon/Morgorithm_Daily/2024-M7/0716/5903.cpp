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

const int mxN = 20010;
int plant[mxN];
vector<tuple<int, int, int, int>> query; // {x, y1, y2, 심을때 0}

void solve(){
    int N; cin >> N;
    while(N--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 10000, y1 += 10000, x2 += 10000, y2 += 10000;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        query.push_back({x1, y1, y2, 0});
        query.push_back({x2, y1, y2, 1});
    }
    sort(query.begin(), query.end());
    int ans = 0, lastx = 0, cnt = 0;
    lastx = get<0>(query[0]);
    for(auto [x, y1, y2, isEnd]: query){
        ans += cnt * (x - lastx);
        lastx = x;
        if(isEnd){
            rep(i, y1, y2) if(--plant[i] == 0) cnt--;
        }
        else{
            rep(i, y1, y2) if(plant[i]++ == 0) cnt++;
        }
    }
    cout << ans;
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