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

// Segment Tree
struct SegmentTree{
    vector<int> tree;
    int sz;

    int pull(int a, int b){
        return max(a, b);
    }

    void init(int N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz);
    }
    
    void set(int i, int x){
        tree[sz+i] = x;
    }

    void build(){
        for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
    }

    void update(int i, int x){
        int idx = sz + i;
        tree[idx] += x;
        while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
    }
    int query(int L, int R){
        if(L > R) return 0;
        int left = L + sz, right = R + sz;
        int ret = 0;
        while(left <= right){
            if((left&1)==1) ret = pull(ret, tree[left++]);
            if((right&1)==0) ret = pull(ret, tree[right--]);
            left >>= 1; right >>= 1;
        }
        return ret;
    }
}ST;

int N, Q;
vector<pii> years;
map<int, int> mp;

void solve(){
    cin >> N;
    rep(i, 0, N){
        int year, rain;
        cin >> year >> rain;
        years.push_back({year, rain});
    }
    rep(i, 0, N) mp[years[i].first] = i;
    mp[INT_MAX] = N;

    ST.init(N);
    rep(i, 0, N) ST.set(i, years[i].second);
    ST.build();
    
    cin >> Q;
    while(Q--){
        int a, b; cin >> a >> b;

        // 모르는 년도일 경우
        if(mp.find(a) == mp.end() || mp.find(b) == mp.end()){
            if(mp.find(a) != mp.end()){
                int ma = mp[a], mb = mp.lower_bound(b)->second-1;
                // cout << "case 1: " << ma << " " << mb << endl;
                if(ST.query(ma, ma) > ST.query(ma+1, mb)) cout << "maybe\n";
                else cout << "false\n";
            }
            else if(mp.find(b) != mp.end()){
                int ma = mp.lower_bound(a)->second, mb = mp[b];
                // cout << "case 2: " << ma << " " << mb << endl;
                if(ST.query(ma, mb-1) < ST.query(mb, mb)) cout << "maybe\n";
                else cout << "false\n";
            }
            else cout << "maybe\n";
            continue;
        }


        int ma = mp[a], mb = mp[b];

        int qa = ST.query(ma, ma), qb = ST.query(mb, mb), qc = ST.query(ma+1, mb-1);
        if(qa >= qb && qc < qb){
            if(b-a == mb-ma) cout << "true\n";
            else cout << "maybe\n";
        }
        else{
            cout << "false\n";
        }
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