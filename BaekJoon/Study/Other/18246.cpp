#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct SegmentTree{
    vector<int> tree;
    int sz;
    void init(int N, vector<int>& lst){
        sz = N;
        tree.resize(2*sz);
        for(int i = 0; i < N; i++){
            tree[sz+i] = lst[i];
        }
        for(int i = sz-1; i > 0; i--){
            tree[i] = max(tree[i<<1], tree[i<<1|1]);
        }
    }
    void update(int i, int x){
        int idx = sz + i;
        tree[idx] = x;
        while(idx >>= 1){
            tree[idx] = max(tree[idx<<1], tree[idx<<1|1]);
        }
    }
    int query(int L, int R){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1)==1) ret = max(ret, tree[left++]);
            if((right&1)==0) ret = max(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

struct SegmentTree2D{
    vector<SegmentTree> ST;
    int sz;
    void init(int N, int M, vector<vector<int>>& lst){
        sz = N;
        ST.resize(2*sz);
        for(int i = 0; i<N; i++){
            ST[sz+i].init(M, lst[i]);
        }
        vector<int> tmp(M, 0);
        for(int i = N; i<sz; i++){
            ST[sz+i].init(M, tmp);
        }
        for(int i = sz-1; i > 0; i--){
            ST[i].init(M, tmp);
            for(int j = 0; j < M; j++){
                int q1 = ST[i<<1].query(j, j);
                int q2 = ST[i<<1|1].query(j, j);
                ST[i].update(j, max(q1, q2));
            }
        }
    }
    void update(int i, int j, int x){
        int idx = sz + i;
        ST[idx].update(j, x);
        while(idx >>= 1){
            int q1 = ST[idx<<1].query(j, j);
            int q2 = ST[idx<<1|1].query(j, j);
            ST[idx].update(j, max(q1, q2));
        }
    }
    int query(int L, int R, int U, int D){
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1) == 1) ret = max(ret, ST[left++].query(U, D));
            if((right&1) == 0) ret = max(ret, ST[right--].query(U, D));
            left >>= 1; right >>= 1;
        }
        return ret;
    }
};

int N, M;
vector<vector<int>> board(1510, vector<int>(1510));
SegmentTree2D seg;

void solve(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        board[r1][c1]++;
        board[r1][c2]--;
        board[r2][c1]--;
        board[r2][c2]++;
    }
    // imos
    for(int i = 0; i < 1510; i++){
        for(int j = 1; j < 1510; j++){
            board[i][j] += board[i][j-1];
        }
    }
    for(int i = 1; i < 1510; i++){
        for(int j = 0; j < 1510; j++){
            board[i][j] += board[i-1][j];
        }
    }

    seg.init(1510, 1510, board);
    for(int i = 0; i < M; i++){
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << seg.query(r1, r2-1, c1, c2-1) << '\n';
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