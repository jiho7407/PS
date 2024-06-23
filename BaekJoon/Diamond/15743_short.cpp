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

const int mxN = 1e5+1;
int par[17][mxN], dep[mxN];
int radius[mxN][2];
int rad[mxN];
int treecnt = 0;

int getLCA(int a, int b){
    if(dep[a] > dep[b]) swap(a, b);
    int diff = dep[b] - dep[a];
    rep(i, 0, 17) if(diff & (1<<i)) b = par[i][b];
    if(a == b) return a;
    for(int i = 16; i >= 0; i--){
        if(par[i][a] != par[i][b]){
            a = par[i][a];
            b = par[i][b];
        }
    }
    return par[0][a];
}

int getDist(int a, int b){
    return dep[a] + dep[b] - 2*dep[getLCA(a, b)];
}

void solve(){
    int Q; cin >> Q;
    int N = 1;
    while(Q--){
        char op; int x;
        cin >> op >> x;
        if(op == 'B'){
            if(x == -1){
                radius[N][0] = radius[N][1] = N;
                dep[N] = 0;
                rep(i, 0, 17) par[i][N] = N;
            }
            else{
                par[0][N] = x;
                dep[N] = dep[x] + 1;
                rep(i, 1, 17) par[i][N] = par[i-1][par[i-1][N]];
                int root = par[16][N];
                int d1 = getDist(N, radius[root][0]);
                int d2 = getDist(N, radius[root][1]);
                if(d1 > rad[root]) rad[root] = d1, radius[root][1] = N;
                if(d2 > rad[root]) rad[root] = d2, radius[root][0] = N;
            }
            N++;
        }
        else{
            int root = par[16][x];
            cout << max(getDist(x, radius[root][0]), getDist(x, radius[root][1])) << '\n';
        }
    }
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