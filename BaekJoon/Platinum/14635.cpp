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

ll N, M;
ll board[100][100];
ll status[100][100];
vector<ll> rs, cs;

vector<ll> adj[100];
ll AM[100], BM[100];
bool visited[100];

bool dfs(ll a){
    if(visited[a]) return false;
    visited[a] = true;
    for(auto b: adj[a]){
        if(BM[b] == -1 || dfs(BM[b])){
            AM[a] = b;
            BM[b] = a;
            return true;
        }
    }
    return false;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) rep(j, 0, M) cin >> board[i][j];

    rep(i, 0, N){
        ll mx = -1;
        rep(j, 0, M) mx = max(mx, board[i][j]);
        rs.push_back(mx);
    }

    rep(j, 0, M){
        ll mx = -1;
        rep(i, 0, N) mx = max(mx, board[i][j]);
        cs.push_back(mx);
    }

    rep(i, 0, N) rep(j, 0, M) if(rs[i] == cs[j] && board[i][j] != 0) adj[i].push_back(j);

    fill(AM, AM+100, -1);
    fill(BM, BM+100, -1);
    rep(i, 0, N){
        fill(visited, visited+100, false);
        dfs(i);
    }
    rep(i, 0, N) if(AM[i] != -1){
        ll j = AM[i];
    }

    ll ans = 0;
    rep(i, 0, N) rep(j, 0, M) ans += max(0LL, board[i][j]-1);
    rep(i, 0, N) ans -= max(0LL, rs[i]-1);
    rep(j, 0, M) if(BM[j] == -1) ans -= max(0LL, cs[j]-1);
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