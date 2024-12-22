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
bool ok[200000];
int subt[200000], par[200000];

void dfs(int c, int p){
    par[c] = p;
    subt[c] = 1;
    for(auto n: links[c]){
        if(n == p) continue;
        dfs(n, c);
        subt[c] += subt[n];
    }
}

void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int a, b; cin >> a >> b;
        a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }

    int a, b, x;
    cin >> a >> b >> x;
    a--; b--; x--;
    if(a == b){
        cout << N;
        return;
    }

    dfs(x, -1);

    int pa = a, pb = b;
    while(par[pa] != x) pa = par[pa];
    while(par[pb] != x) pb = par[pb];

    if(a == x || b == x){
        if(a == x) swap(pa, pb);
        cout << N - subt[pa];
    }
    else{
        cout << N - subt[pa] - subt[pb];
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