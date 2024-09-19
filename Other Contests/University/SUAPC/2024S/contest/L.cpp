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

const int MAXN = 2024, MAXM = 2024; // 0-based로 사용. 그렇지 않을시 match(N+1) 조심하기.
struct BipartiteMatching{
    vector<int> graph[MAXN];
    int dis[MAXN], L[MAXN], R[MAXM], vis[MAXN];
    void clear(){ rep(i, 0, MAXN) graph[i].clear(); }
    void addEdge(int l, int r){ graph[l].push_back(r); }

    bool bfs(int n){
        queue<int> q;
        bool ok = 0;
        memset(dis, 0, sizeof(dis));
        for(int i = 0; i < n; i++){
            if(L[i] == -1){
                q.push(i);
                dis[i] = 1;
            }
        }
        while(!q.empty()){
            int l = q.front(); q.pop();
            for(auto &r : graph[l]){
                if(R[r] == -1) ok = 1;
                else if(!dis[R[r]]){
                    dis[R[r]] = dis[l] + 1;
                    q.push(R[r]);
                }
            }
        }
        return ok;
    }

    bool dfs(int l){
        if(vis[l]) return 0;
        vis[l] = 1;
        for(auto &r : graph[l]){
            if(R[r] == -1 || (!vis[R[r]] && dis[R[r]] == dis[l] + 1 && dfs(R[r]))){
                L[l] = r;
                R[r] = l;
                return true;
            }
        }
        return 0;
    }

    int match(int n){
        memset(L, -1, sizeof(L));
        memset(R, -1, sizeof(R));
        int ret = 0;
        while(bfs(n)){
            memset(vis, 0, sizeof(vis));
            rep(i, 0, n){
                if(L[i] == -1 && dfs(i)) ret++;
            }
        }
        return ret;
    }
}Bpm;

vector<int> res1, res2;

void solve(){
    int N; cin >> N; res1.resize(N); res2.resize(N);
    rep(i, 0, N) rep(j, 0, N){
        if((int)(i&j) == 0) Bpm.addEdge(i, j);
    }
    Bpm.match(N);

    cout << "? ";
    rep(i, 0, N) cout << i << ' ';
    cout << endl; cout.flush();
    rep(i, 0, N) cin >> res1[i];

    cout << "? ";
    rep(i, 0, N) cout << Bpm.L[i] << ' ';
    cout << endl; cout.flush();
    rep(i, 0, N) cin >> res2[i];

    cout << "! ";
    rep(i, 0, N){
        rep(j, 0, N){
            if(((int)(j|i) == res1[i]) && ((int)(j|Bpm.L[i]) == res2[i])){
                cout << j << ' ';
                break;
            }
        }
    }
    cout << endl; cout.flush();
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