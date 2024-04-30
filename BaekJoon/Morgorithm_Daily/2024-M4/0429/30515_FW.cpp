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

// Fenwick Tree
// 펜윅트리는 1기반 인덱싱. 0 넣지 않게 조심

struct Fenwick{
    vector<ll> tree;
    Fenwick(int n){
        tree.resize(n+1);
        rep(i, 1, n+1) tree[i] = i & -i;
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
    int N; cin >> N;
    Fenwick fenwick(N);
    vector<pii> flowers; // flower, index
    rep(i, 0, N){
        int flower; cin >> flower;
        flowers.push_back({flower, i});
    }
    sort(flowers.begin(), flowers.end());
    set<pii> idxset;
    rep(i, 0, N){idxset.insert({flowers[i].second, i});}

    int Q; cin >> Q;
    while(Q--){
        int cmd, l, r, k;
        cin >> cmd >> l >> r;
        l--; r--;
        if(cmd == 1){
            cin >> k;
            auto low = lower_bound(flowers.begin(), flowers.end(), (pii){k, l}) - flowers.begin();
            auto up = upper_bound(flowers.begin(), flowers.end(), (pii){k, r}) - flowers.begin();
            cout << fenwick.query(up) - fenwick.query(low) << '\n';
        }
        else{
            auto it = idxset.lower_bound({l, 0});
            while(it != idxset.end() && it->first <= r){
                fenwick.update(it->second+1, -1);
                idxset.erase(it++);
            }
        }
        // rep(i, 0, N) cout << fenwick.query(i+1) - fenwick.query(i) << ' ';
        // cout << "\n";
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