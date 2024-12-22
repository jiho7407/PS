#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
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
      rep(i, 0, 2*sz) tree[i] = -1e9;
   }
   
   void set(int i, int x){
      tree[sz+i] = x;
   }

   void build(){
      for(int i = sz-1; i > 0; i--) tree[i] = pull(tree[i<<1], tree[i<<1|1]);
   }

   void update(int i, int x){
      int idx = sz + i;
      tree[idx] = x;
      while(idx >>= 1) tree[idx] = pull(tree[idx<<1], tree[idx<<1|1]);
   }
   int query(int L, int R){
      int left = L + sz, right = R + sz;
      int ret = -1e9;
      while(left <= right){
         if((left&1)==1) ret = pull(ret, tree[left++]);
         if((right&1)==0) ret = pull(ret, tree[right--]);
         left >>= 1; right >>= 1;
      }
      return ret;
   }
}ST;

bool cmp(pair<pii, int> a, pair<pii, int> b){
    if(a.first.first == b.first.first) return a.first.second > b.first.second;
    return a.first.first < b.first.first;
}

void solve(){
    int N; cin >> N;
    vector<pii> v;
    vector<int> xs;
    rep(i, 0, N){
        int x, y; cin >> x >> y;
        v.push_back({x, y});
        xs.push_back(x);
        xs.push_back(y);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    map<int, int> mp;
    rep(i, 0, xs.size()) mp[xs[i]] = i;
    vector<pair<pii, int>> lst;
    rep(i, 0, N){
        lst.push_back({{mp[v[i].first], mp[v[i].second]}, i});
    }
    sort(lst.begin(), lst.end(), cmp);
    int sz = xs.size()+1;
    ST.init(sz);
    vector<int> ans(N, -1);

    set<int> st;

    rep(i, 0, N){
        auto [L, R] = lst[i].first;
        int j = i;
        while(j < N && lst[j].first == lst[i].first){
            j++;
        }
        if(j-i > 1){
            rep(k, i, j){
                ans[lst[k].second] = 0;
            }
            ST.update(R, L);
            st.insert(R);
            i = j-1;
        }
        else{
            auto it = st.lower_bound(R);
            if(it == st.end()) ans[lst[i].second] = 0;
            else{
                int mxL = ST.query(R, sz-1);
                // cout << i << ' ' << L << ' ' << R << ' ' << mxL << ' ' << *it << endl;
                assert(mxL != -1e9);
                ans[lst[i].second] = max(0, xs[L] - xs[mxL]) + max(0, xs[*it] - xs[R]);
            }
            ST.update(R, L);
            st.insert(R);
        }

        // rep(i, 0, sz) cout << ST.query(i, i) << ' ';
        // cout << '\n';
    }
    // for(auto a: xs) cout << a << ' ';
    // cout << '\n';

    rep(i, 0, N) cout << ans[i] << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}