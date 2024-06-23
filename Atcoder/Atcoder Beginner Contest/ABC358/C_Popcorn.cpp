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

int N, M;
string board[10];
bool arr[10];

int btr(int cur, int cnt){
    bool flag = true;
    rep(i, 0, M) if(!arr[i]) flag = false;
    if(flag) return cnt;
    if(cur == N) return 1e8;
    int ret = 1e8;
    bool tmp[10];
    rep(i, 0, M) tmp[i] = arr[i];
    rep(i, 0, M){
        if(board[cur][i] == 'o') arr[i] = 1;
    }
    ret = min(ret, btr(cur + 1, cnt + 1));
    rep(i, 0, M) arr[i] = tmp[i];
    ret = min(ret, btr(cur + 1, cnt));
    return ret;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> board[i];
    fill(arr, arr + M, 0);
    cout << btr(0, 0);
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