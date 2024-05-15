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
vector<int> links[200000];
bool leaf[200000];
int Adist[200000], Bdist[200000], Cdist[200000];

void dfs(int cur, int par, int dist[]){
    for(auto nxt: links[cur]){
        if(nxt == par) continue;
        leaf[cur] = false;
        dist[nxt] = dist[cur] + 1;
        dfs(nxt, cur, dist);
    }
    return;
}

void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int a, b; cin >> a >> b; a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    int A, B, C; cin >> A >> B >> C; A--; B--; C--;
    if(links[A].size() == 1) {cout << "YES"; return;}
    fill(leaf, leaf+N, true);
    fill(Adist, Adist+N, 0);
    fill(Bdist, Bdist+N, 0);
    fill(Cdist, Cdist+N, 0);
    dfs(A, -1, Adist);
    dfs(B, -1, Bdist);
    dfs(C, -1, Cdist);
    rep(i, 0, N){
        if(!leaf[i]) continue;
        if(Adist[i] < Bdist[i] && Adist[i] < Cdist[i]){
            cout << "YES";
            return;
        }
    }
    cout << "NO";

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