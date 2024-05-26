#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

// PST
struct Node{
    Node *L, *R;
    ll V;
    Node(){ L = R = nullptr; V = 0; }
};

Node *root[100001]; // root[i]: i번째 버전의 루트 노드
int N, M, A[100001], sortA[100001];
map<int, int> mp;

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
    if(S==E){ cur->V = V; return; }
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

ll query(Node *prev, Node *cur, int S, int E, int K){
    if(S == E) return S;
    int DIFF = cur->L->V - prev->L->V;
    int M = (S+E)>>1;
    if(K <= DIFF) return query(prev->L, cur->L, S, M, K);
    else return query(prev->R, cur->R, M+1, E, K-DIFF);
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) sortA[i] = A[i];
    sort(sortA, sortA+N);
    rep(i, 0, N) mp[sortA[i]] = i;

    root[0] = new Node();
    build(root[0], 0, N-1);
    rep(i, 0, N){
        root[i+1] = new Node();
        update(root[i], root[i+1], 0, N-1, mp[A[i]], 1);
    }
    rep(i, 0, M){
        int l, r, k; cin >> l >> r >> k;
        cout << sortA[query(root[l-1], root[r], 0, N-1, k)] << '\n';
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