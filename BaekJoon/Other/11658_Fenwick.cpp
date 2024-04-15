#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct Fenwick2D{
    vector<vector<ll>> tree;
    Fenwick2D(int n, int m){
        tree.resize(n+1, vector<ll>(m+1));
    }
    void update(int x, int y, ll diff){
        for(int i = x; i < tree.size(); i += (i & -i)){
            for(int j = y; j < tree[i].size(); j += (j & -j)){
                tree[i][j] += diff;
            }
        }
    }
    ll query(int x, int y){
        ll ret = 0;
        for(int i = x; i > 0; i -= (i & -i)){
            for(int j = y; j > 0; j -= (j & -j)){
                ret += tree[i][j];
            }
        }
        return ret;
    }
};

int N, M;

void solve(){
    cin >> N >> M;
    Fenwick2D fenwick(N, N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int x;
            cin >> x;
            fenwick.update(i, j, x);
        }
    }
    for(int i = 0; i < M; i++){
        int cmd;
        cin >> cmd;
        if(cmd == 0){
            int x, y, c;
            cin >> x >> y >> c;
            ll diff = c - (fenwick.query(x, y) - fenwick.query(x-1, y) - fenwick.query(x, y-1) + fenwick.query(x-1, y-1));
            fenwick.update(x, y, diff);
        }else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << fenwick.query(x2, y2) - fenwick.query(x1-1, y2) - fenwick.query(x2, y1-1) + fenwick.query(x1-1, y1-1) << '\n';
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