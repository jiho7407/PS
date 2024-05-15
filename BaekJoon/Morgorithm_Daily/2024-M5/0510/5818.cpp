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

const int mxN = 1000;
int N, M[mxN][mxN], C[mxN];
int root[mxN];
int ans = 0;

int find(int x){
    if(root[x] == x) return x;
    root[x] = find(root[x]);
    return root[x];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(a > b) swap(a, b);
    root[b] = a;
    C[a] = min(C[a], C[b]);
}

void solve(){
    cin >> N;
    rep(i, 0, N) rep(j, 0, N) cin >> M[i][j];
    rep(i, 0, N) cin >> C[i]; 
    rep(i, 0, N) root[i] = i;

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    rep(i, 0, N) rep(j, i+1, N) pq.push({M[i][j], {i, j}});
    while(!pq.empty()){
        auto [cost, edge] = pq.top(); pq.pop();
        auto [a, b] = edge;
        if(find(a) == find(b)) continue;
        if(cost > max(C[find(a)], C[find(b)])) continue;
        merge(a, b);
        ans += cost;
    }
    rep(i, 0, N) if(find(i) == i) ans += C[i];
    cout << ans << "\n";
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