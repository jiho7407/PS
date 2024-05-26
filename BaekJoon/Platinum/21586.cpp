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

const int mxN = 1<<19;
string S;
int N;

struct SuffixArray{
    string S;
    int N, cnt[mxN], ord[mxN], tmp[mxN], SA[mxN], LCP[mxN];

    SuffixArray(string S): S(S){
        N = S.size();
        makeSA();
        makeLCP();
    }

    void makeSA(){
        rep(i, 0, N){
            SA[i] = i;
            ord[i] = S[i];
        }
        int d = 1;
        int pnt = 1;
        while(1){
            // 기수 정렬
            // cnt: 같은 그룹의 개수, ord: 그룹 번호, SA: 정렬된 순서
            fill(cnt, cnt+mxN, 0);
            rep(i, 0, N) cnt[ord[min(i+d, N)]]++; // i+d번째 문자를 기준으로 그룹 나누기
            rep(i, 0, max(N, 255)) cnt[i+1] += cnt[i];
            for(int i = N-1; i>=0; i--) tmp[--cnt[ord[min(i+d, N)]]] = i;
            
            fill(cnt, cnt+mxN, 0);
            rep(i, 0, N) cnt[ord[i]]++; // i번째 문자를 기준으로 그룹 나누기
            rep(i, 0, max(N, 255)) cnt[i+1] += cnt[i];
            for(int i = N-1; i>=0; i--) SA[--cnt[ord[tmp[i]]]] = tmp[i];


            // 새로운 그룹 번호 부여
            if(pnt == N) break;
            pnt = 1;
            tmp[SA[0]] = 1;
            rep(i, 1, N){
                if(ord[SA[i-1]] != ord[SA[i]] || ord[SA[i-1]+d] != ord[SA[i]+d]) pnt++;
                tmp[SA[i]] = pnt;
            }
            rep(i, 0, N) ord[i] = tmp[i];
            d <<= 1;
        }
    }

    void makeLCP(){
        rep(i, 0, N) tmp[SA[i]] = i;
        for(int i=0, k=0; i<N; i++, k=max(k-1, 0)){
            if(tmp[i] == N-1) continue;
            for(int j=SA[tmp[i]+1]; S[i+k]==S[j+k]; k++);
            LCP[tmp[i]] = k;
        }
    }
};

struct Node{
    Node *L, *R;
    ll V;
    Node(){ L = R = nullptr; V = 0; }
};

struct PersistentSegmentTree{
    Node *root[200001]; // root[i]: i번째 버전의 루트 노드

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
        update(root[prev], root[cur], 0, N-1, X, V);
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

    ll query(int prev, int cur, int K){
        return query(root[prev], root[cur], 0, N-1, K);
    }

    ll query(Node *prev, Node *cur, int S, int E, int K){
        if(S == E) return S;
        int DIFF = cur->L->V - prev->L->V;
        int M = (S+E)>>1;
        if(K <= DIFF) return query(prev->L, cur->L, S, M, K);
        else return query(prev->R, cur->R, M+1, E, K-DIFF);
    }
}PST;

pii get_bound(int SA[],string T){
    int lb, up;

    // Lower Bound
    int lo = 0, hi = N;
    while(lo<hi){
        int mid = (lo+hi)>>1;
        if(S.compare(SA[mid], T.size(), T) < 0) lo = mid+1;
        else hi = mid;
    }
    lb = lo;

    // Upper Bound
    lo = 0, hi = N;
    while(lo<hi){
        int mid = (lo+hi)>>1;
        if(S.compare(SA[mid], T.size(), T) <= 0) lo = mid+1;
        else hi = mid;
    }
    up = hi;

    return {lb, up};
}

void solve(){
    cin >> S;
    SuffixArray* SA = new SuffixArray(S);

    N = S.size();
    PST.root[0] = new Node();
    PST.build(PST.root[0], 0, N-1);
    rep(i, 0, N){
        PST.root[i+1] = new Node();
        PST.update(i, i+1, SA->SA[i], 1);
    }

    int M, K; cin >> M;
    while(M--){
        string T; cin >> T >> K;
        pii bound = get_bound(SA->SA, T);
        if(bound.second - bound.first < K){
            cout << "-1\n";
            continue;
        }
        cout << PST.query(bound.first, bound.second, K)+1 << '\n';
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