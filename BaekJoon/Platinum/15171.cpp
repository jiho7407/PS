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
vector<int> links[200000];
bool visited[200000];
int st[200000];

void dfs(int cur, int status){
    visited[cur] = 1;
    st[cur] = status;

    for(auto nxt : links[cur]){
        if(visited[nxt]) continue;
        visited[nxt] = 1;
        dfs(nxt, 3-status);
    }
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        char op; int cnt;
        cin >> op >> cnt;
        if(op == 'C'){
            while(cnt--){
                int x; cin >> x; x--;
                links[i].push_back(x);
                links[x].push_back(i);
            }
        }
        else{
            vector<bool> nxt(N, 1);
            while(cnt--){
                int x; cin >> x; x--;
                nxt[x] = 0;
            }
            rep(j, 0, N){
                if(!nxt[j]) continue;
                if(i == j) continue;
                links[i].push_back(j);
                links[j].push_back(i);
                break;
            }
        }
    }

    rep(i, 0, N) if(links[i].empty()){
        cout << "Impossible";
        return;
    }

    rep(i, 0, N) if(!visited[i]) dfs(i, 1);
    rep(i, 0, N) cout << (st[i] == 1 ? 'S' : 'V');
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