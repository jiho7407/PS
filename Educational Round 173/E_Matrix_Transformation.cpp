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

int N, M;
vector<vector<int>> A, B;

bool get_bit(int x, int i){
    return (x>>i)&1;
}

struct Graph{
    int V;
    vector<vector<int>> gph;
    vector<int> visited;
    // 0: 방문하지 않은 노드
    // 1: 방문했으나 dfs가 끝나지 않은 노드
    // 2: 방문했고 dfs가 끝난 노드

    Graph(int V): V(V){
        gph.resize(V);
        visited.resize(V);
    }

    void add_edge(int u, int v){
        gph[u].push_back(v);
    }

    bool dfs_cycle(int cur){
        if(visited[cur] == 1) return true;
        if(visited[cur] == 2) return false;

        visited[cur] = 1;
        for(auto nxt: gph[cur]){
            if(dfs_cycle(nxt)) return true;
        }
        visited[cur] = 2;
        return false;
    }
};

bool calc(int bit){
    vector<bool> rowDo(N, 0), colDo(M, 0);
    Graph G(N+M);
    rep(i, 0, N) rep(j, 0, M){
        bool Abit = get_bit(A[i][j], bit);
        bool Bbit = get_bit(B[i][j], bit);

        if(Abit != Bbit){
            if(Bbit) colDo[j] = true;
            else rowDo[i] = true;
        }

        if(Bbit) G.add_edge(i, N+j);
        else G.add_edge(N+j, i);
    }
    rep(i, 0, N) if(rowDo[i] && G.dfs_cycle(i)) return false;
    rep(i, 0, M) if(colDo[i] && G.dfs_cycle(N+i)) return false;
    return true;
}

void solve(){
    cin >> N >> M;
    A = vector<vector<int>>(N, vector<int>(M));
    B = vector<vector<int>>(N, vector<int>(M));
    rep(i, 0, N) rep(j, 0, M) cin >> A[i][j];
    rep(i, 0, N) rep(j, 0, M) cin >> B[i][j];


    bool flag = true;

    rep(bit, 0, 31){
        if(calc(bit)) continue;
        flag = false;
        break;
    }

    if(flag) cout << "Yes\n";
    else cout << "No\n";
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