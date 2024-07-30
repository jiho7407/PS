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

int N, M, sz;
const int mxN = 100001;

// Persistent Segment Tree
// PST

struct Node{
    Node *L, *R;
    ll V;
    Node(){ L = R = nullptr; V = 0; }
};

struct PersistentSegmentTree{
    Node *root[100001]; // root[i]: i번째 버전의 루트 노드

    void build(Node *node, int S, int E){
        if(S == E){ node->V = 0; return; }
        int M = (S+E)>>1;
        node->L = new Node();
        node->R = new Node();
        build(node->L, S, M);
        build(node->R, M+1, E);
        node->V = node->L->V + node->R->V;
    }

    void update(int prev, int cur, int X, int V){
        update(root[prev], root[cur], 0, sz-1, X, V);
    }

    void update(Node *prev, Node *cur, int S, int E, int X, int V){
        if(X<S || X>E) return;
        if(S==E){ cur->V += V; return; }
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

    ll query(Node *cur1, Node *cur2, Node *LCA, Node *PLCA, int S, int E, int K){
        if(S == E) return S;
        // cout << "cur1: " << cur1->V << " cur2: " << cur2->V << " LCA: " << LCA->V << " PLCA: " << PLCA->V << endl;
        int DIFF = cur1->L->V + cur2->L->V - LCA->L->V - PLCA->L->V;

        int curval = cur1->V + cur2->V - LCA->V - PLCA->V;
        // cout << "S: " << S << " E: " << E << " DIFF: " << DIFF << " curval: " << curval << endl;
        int M = (S+E)>>1;
        // cout << "M: " << M << " K: " << K << endl;
        if(K <= DIFF) return query(cur1->L, cur2->L, LCA->L, PLCA->L, S, M, K);
        else return query(cur1->R, cur2->R, LCA->R, PLCA->R, M+1, E, K-DIFF);
    }
}PST;

// 가중치 좌표압축 관련
int wht[mxN];
vector<int> whts;
map<int, int> mp;

// 트리 관련
vector<int> links[mxN];
int par[mxN][20], dep[mxN];

void maketree(int c, int p){
    par[c][0] = p;
    dep[c] = dep[p] + 1;
    PST.root[c] = new Node();
    PST.update(p, c, wht[c], 1);
    // cout << "c: " << c << " p: " << p << " wht[c]: " << wht[c] << endl;
    for(auto n: links[c]){
        if(n == p) continue;
        maketree(n, c);
    }
}

void makeLCA(){
    rep(j, 1, 20){
        rep(i, 0, N+1){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
}

int getLCA(int a, int b){
    if(dep[a] < dep[b]) swap(a, b);
    int diff = dep[a] - dep[b];
    rep(i, 0, 20){
        if(diff & (1<<i)) a = par[a][i];
    }
    if(a == b) return a;
    for(int i=19; i>=0; i--){
        if(par[a][i] != par[b][i]){
            a = par[a][i];
            b = par[b][i];
        }
    }
    return par[a][0];
}

void solve(){
    cin >> N >> M;

    // 가중치 좌표압축
    rep(i, 1, N+1){
        cin >> wht[i];
        whts.push_back(wht[i]);
    }
    sort(whts.begin(), whts.end());
    whts.erase(unique(whts.begin(), whts.end()), whts.end());
    rep(i, 0, whts.size()) mp[whts[i]] = i;
    rep(i, 1, N+1) wht[i] = mp[wht[i]];

    // 트리 만들기
    rep(i, 0, N-1){
        int a, b; cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    PST.root[0] = new Node();
    sz = 1;
    while(sz < N) sz <<= 1;
    PST.build(PST.root[0], 0, sz-1);
    maketree(1, 0);
    makeLCA();

    // rep(i, 0, N+1){
    //     cout << PST.root[i]->V << ' ';
    // }
    // cout << '\n';

    // 쿼리 처리
    while(M--){
        int X, Y, K; cin >> X >> Y >> K;
        int LCA = getLCA(X, Y);
        int PLCA = par[LCA][0];
        int ans = PST.query(PST.root[X], PST.root[Y], PST.root[LCA], PST.root[PLCA], 0, sz-1, K);
        // cout << X << ' ' << Y << ' ' << LCA << ' ' << PLCA << ' ' << ans << ' ';
        cout << whts[ans] << '\n';
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