#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
set<pii> s;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

bool sfind(int x, int y){
    return s.find({x, y}) != s.end();
}

bool check(int dir, int x, int y){ // 위 오 아 왼
    if(dir==0){
        if(sfind(x, y-1) || sfind(x, y)) return true;
    }
    else if(dir==1){
        if(sfind(x+1, y) || sfind(x, y)) return true;
    }
    else if(dir==2){
        if(sfind(x+1, y-1) || sfind(x+1, y)) return true;
    }
    else if(dir==3){
        if(sfind(x, y-1) || sfind(x+1, y-1)) return true;
    }
    return false;
}

void solve(){
    cin >> N;
    pii start = {1e9, 1e9};
    rep(i, 0, N){
        int a, b; cin >> a >> b;
        s.insert({a, b});
        if(a < start.first || (a == start.first && b < start.second)){
            start = {a, b};
        }
    }

    auto [cx, cy] = start;
    int cd = 1;
    int ans = 0;
    do{
        rep(d, 0, 4){
            int nd = (cd + d + 3) % 4;
            if(check(nd, cx, cy)){
                cx = cx + dx[nd];
                cy = cy + dy[nd];
                cd = nd;
                ans++;
                break;
            }
        }
    }while(start != make_pair(cx, cy));
    cout << ans << '\n';
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