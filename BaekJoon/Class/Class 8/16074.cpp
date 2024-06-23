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

const int mxH = 1e6+1, mxQ = 1e5;
int N, M, Q;
int board[500][500];
vector<pii> height[mxH];
vector<pair<pii, pii>> query;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

struct UnionFind{
    int par[250000];

    void init(int N, int M){
        rep(i, 0, N*M) par[i] = i;
    }

    int find(int x, int y){
        return find(x*M+y);
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    
    void merge(int x1, int y1){
        int idx = x1*M+y1;
        rep(d, 0, 4){
            int nx = x1+dx[d], ny = y1+dy[d];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[x1][y1] < board[nx][ny]) continue;
            merge2(idx, nx*M+ny);
        }
    }

    void merge2(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(x > y) swap(x, y);
        par[y] = x;
    }
}UF;

int ng[mxQ], ok[mxQ];
vector<int> pbs[mxH];

void solve(){
    cin >> N >> M >> Q;
    rep(i, 0, N) rep(j, 0, M) cin >> board[i][j];
    rep(i, 0, N) rep(j, 0, M) height[board[i][j]].push_back({i, j});
    rep(i, 0, Q){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        query.push_back({{x1, y1}, {x2, y2}});
    }
    rep(i, 0, Q) ng[i] = 0, ok[i] = mxH;

    while(1){
        rep(i, 0, mxH) pbs[i].clear();
        bool flag = 0;
        rep(i, 0, Q) if(ok[i] - ng[i] > 1){
            flag = 1;
            int mid = (ok[i] + ng[i])>>1;
            pbs[mid].push_back(i);
        }
        if(!flag) break;

        UF.init(N, M);
        rep(i, 0, mxH){
            for(auto [x, y]:height[i]) UF.merge(x, y);
            for(auto q:pbs[i]){
                auto [x1, y1] = query[q].first;
                auto [x2, y2] = query[q].second;
                if(x1 == x2 && y1 == y2){
                    ng[q] = ok[q] = board[x1][y1];
                    continue;
                }
                if(UF.find(x1, y1) == UF.find(x2, y2)) ok[q] = i;
                else ng[q] = i;
            }
        }
    }
    rep(i, 0, Q){
        cout << ok[i] << '\n';
    }
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