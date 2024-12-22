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
vector<int> nxt[1000];
bool flag[1000];

void solve(){
    cin >> N;
    rep(i, 0, N){
        int a, b; cin >> a >> b;
        nxt[i].push_back(a-1);
        nxt[i].push_back(b-1);
    }

    flag[0] = 1;
    rep(k, 0, 100){
        if(k >= 10 && !flag[0]){
            cout << k;
            return;
        }
        vector<bool> flag2(N, false);
        rep(i, 0, N){
            if(!flag[i]) continue;
            for(auto n: nxt[i]) flag2[n] = true;
        }
        rep(i, 0, N) flag[i] = flag2[i];
    }
    cout << -1;
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