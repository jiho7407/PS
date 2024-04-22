#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

struct Fenwick{
    vector<ll> tree;
    Fenwick(int n){
        tree.resize(n+1);
    }
    void update(int idx, ll diff){
        while(idx < tree.size()){
            tree[idx] += diff;
            idx += (idx & -idx);
        }
    }
    ll query(int idx){
        ll ret = 0;
        while(idx > 0){
            ret += tree[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }
};

void solve(){
    int N, M, K;
    cin >> N >> M >> K;
    Fenwick fenwick(N);
    for(int i=1; i<=N; i++){
        ll num; cin >> num;
        fenwick.update(i, num);
    }
    for(int i=0; i<M+K; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            ll diff = c - fenwick.query(b) + fenwick.query(b-1);
            fenwick.update(b, diff);
        }
        else{
            cout << fenwick.query(c) - fenwick.query(b-1) << '\n';
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