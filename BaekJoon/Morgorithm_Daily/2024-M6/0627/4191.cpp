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

int N, M, L;
vector<int> nxt[10000];
bool stand[10000];

void solve(){
    cin >> N >> M >> L;
    rep(i, 0, M){
        int a, b; cin >> a >> b; a--; b--;
        nxt[a].push_back(b);
    }
    fill(stand, stand+N, true);
    rep(i, 0, L){
        int a; cin >> a; a--;
        queue<int> q;
        q.push(a);
        stand[a] = false;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nx: nxt[cur]){
                if(stand[nx]){
                    stand[nx] = false;
                    q.push(nx);
                }
            }
        }
    }
    int ans = 0;
    rep(i, 0, N) if(!stand[i]) ans++;
    cout << ans << '\n';

    rep(i, 0, N) nxt[i].clear();
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