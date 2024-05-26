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
int N, M, A[100001];

void build(Node *node, int S, int E){
    if(S == E){ node->V = A[S]; return; }
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

ll query(Node *node, int S, int E, int L, int R){
    if(R<S || E<L) return 0;
    if(L<=S && E<=R) return node->V;
    int M = (S+E)>>1;
    return query(node->L, S, M, L, R) + query(node->R, M+1, E, L, R);
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    root[0] = new Node();
    build(root[0], 0, N-1);
    cin >> M;
    int cnt = 1;
    rep(i, 0, M){
        int q; cin >> q;
        if(q==1){
            int v, x; cin >> x >> v; x--;
            root[cnt] = new Node();
            update(root[cnt-1], root[cnt], 0, N-1, x, v);
            cnt++;
        }
        else{
            int k, l, r; cin >> k >> l >> r; l--; r--;
            cout << query(root[k], 0, N-1, l, r) << '\n';
        }
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