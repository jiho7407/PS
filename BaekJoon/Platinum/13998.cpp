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

int N, W, H, M;
bool jenga[5000][10000];
ll xys[5000], cnts[5000];
vector<pii> v;

bool unstable(){
    ll xsum = 0, ysum = 0, cnt = 0;
    for(int i = H-1; i>=0; i--){
        
    }
}

void solve(){
    cin >> N >> W >> H >> M;
    rep(i, 0, M){
        int x, y; cin >> x >> y;
        x--; y--;
        v.push_back({x, y});
    }

    fill_n(&jenga[0][0], 5000*10000, 1);
    fill(cnts, cnts+5000, N);
    rep(i, 0, M){
        auto [x, y] = v[i];
        jenga[x][y] = 0;
        if(unstable()){
            cout << "yes" << '\n';
            cout << i+1;
            return;
        }
    }
    cout << "no";
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