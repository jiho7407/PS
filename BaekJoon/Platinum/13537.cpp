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

struct Node{
    Node *L, *R;
    int V;
    Node(){
        L = R = nullptr;
        V = 0;
    }
};

Node *root[100001];

void build(Node *node, int S, int E){
    if(S == E){ node->V = 0; return; }
    int M = (S+E)>>1;
    node->L = new Node();
    node->R = new Node();
    build(node->L, S, M);
    build(node->R, M+1, E);
    node->V = node->L->V + node->R->V;
}

void update(Node *prev, Node *cur, int S, int E, int X, int V){
    if(X<S || X>E) return;
    if(S==E){ cur->V = prev->V + V; return; }
    int M = (S+E)>>1;
    if(X<=M){
        cur->L = new Node();
        cur->R = prev->R;
        update(prev->L, cur->L, S, M, X, V);
    }
    else{
        cur->L = prev->L;
        cur->R = new Node();
        update(prev->R, cur->R, M+1, E, X, V);
    }
    cur->V = cur->L->V + cur->R->V;
}

int query(Node *cur, int S, int E, int X){
    if(S == E) return 0;
    int M = (S+E)>>1;
    if(X <= M) return query(cur->L, S, M, X) + cur->R->V;
    else return query(cur->R, M+1, E, X);
}

int N, Q;
vector<int> A, NA;
map<int, int> mp;
vector<tuple<int, int, int>> Qs;


void solve(){
    cin >> N;
    rep(i, 0, N){
        int x; cin >> x;
        A.push_back(x);
        NA.push_back(x);
    }
    cin >> Q;
    rep(i, 0, Q){
        int a, b, c;
        cin >> a >> b >> c;
        Qs.push_back({a, b, c});
        NA.push_back(c);
    }

    sort(NA.begin(), NA.end());
    NA.erase(unique(NA.begin(), NA.end()), NA.end());
    int sz = NA.size();

    root[0] = new Node();
    build(root[0], 0, sz);
    rep(i, 0, sz) mp[NA[i]] = i;

    rep(i, 0, N){
        root[i+1] = new Node();
        update(root[i], root[i+1], 0, sz, mp[A[i]], 1);
    }
    for(auto [i, j, k]: Qs){
        cout << query(root[j], 0, sz, mp[k]) - query(root[i-1], 0, sz, mp[k]) << '\n';
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