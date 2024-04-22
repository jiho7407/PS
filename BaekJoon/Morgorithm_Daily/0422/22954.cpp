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

int N, M;
vector<pii> links[100001];
int root[100001];
vector<pii> tree[100001];
int edge = 0;
int child[100001];

int find(int x){
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(x < y) root[y] = x;
    else root[x] = y;
}

void maketree(int x, int p){
    for(auto [n, i] : links[x]){
        if(n == p) continue;
        if(find(x) == find(n)) continue;
        merge(x, n);
        tree[x].push_back({n, i});
        maketree(n, x);
        edge++;
        child[x]++;
    }
}

vector<int> node1, node2, edge1, edge2;

void dfs1(int x, int p){
    for(auto [n, i] : tree[x]){
        if(n == p) continue;
        node1.push_back(n);
        edge1.push_back(i);
        dfs1(n, x);
    }
}

void dfs2(int x, int p){
    for(auto [n, i] : tree[x]){
        if(n == p) continue;
        node2.push_back(n);
        edge2.push_back(i);
        dfs2(n, x);
    }
}

void solve(){
    cin >> N >> M;
    rep(i, 1, N+1) root[i] = i;
    rep(i, 1, M+1){
        int a, b;
        cin >> a >> b;
        links[a].push_back({b, i});
        links[b].push_back({a, i});
    }
    if(N<=2) {cout << -1; return;}

    fill(child, child+N+1, 0);
    rep(i, 1, N+1){
        if(root[i] == i) maketree(i, 0);
    }
    set <int> s;
    rep(i, 1, N+1) s.insert(find(i));
    if(s.size() >= 3){cout << -1; return;}
    if(s.size()==1){
        int N2, M2;
        rep(i, 1, N+1){
            if(child[i] == 0){
                N2 = i;
                break;
            }
        }
        cout << N-1 << " " << 1 << "\n";
        rep(i, 1, N+1){
            if(i == N2) continue;
            cout << i << " ";
        }
        cout << "\n";
        rep(i, 1, N+1){
            for(auto [n, j] : tree[i]){
                if(n == N2) continue;
                cout << j << " ";
            }
        }
        cout << "\n" << N2 << "\n";
        cout << "\n";
    }
    else{
        int N1=-1, N2=-1;
        for(int elem: s){
            if(N1 == -1) N1 = elem;
            else N2 = elem;
        }
        node1.push_back(N1);
        dfs1(N1, 0);
        node2.push_back(N2);
        dfs2(N2, 0);
        if(node1.size() == node2.size()){cout << -1; return;}
        cout << node1.size() << " " << node2.size() << "\n";
        for(int elem: node1) cout << elem << " ";
        cout << "\n";
        for(int elem: edge1) cout << elem << " ";
        cout << "\n";
        for(int elem: node2) cout << elem << " ";
        cout << "\n";
        for(int elem: edge2) cout << elem << " ";
        cout << "\n";
    }
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