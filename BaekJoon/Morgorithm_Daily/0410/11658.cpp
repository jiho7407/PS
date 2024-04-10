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

int N, M, Q;
Fenwick2D FT(0, 0);

void solve(){
    cin >> N >> M >> Q;
    FT = Fenwick2D(N, M);
    while(Q--){
        int cmd; cin >> cmd;
        if(cmd == 1){
            int x1, y1, x2, y2, d;
            cin >> x1 >> y1 >> x2 >> y2 >> d;
            FT.update(x1, y1, d);
            FT.update(x1, y2+1, -d);
            FT.update(x2+1, y1, -d);
            FT.update(x2+1, y2+1, d);
        }
        else{
            int x, y;
            cin >> x >> y;
            cout << FT.query(x, y) << '\n';
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