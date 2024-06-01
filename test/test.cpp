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

const ld mINF = -1e20;
struct SegmentTree{
    struct Node{
        vector<pll> cvh;
        vector<ld> intersection;
        Node(){
            cvh.push_back({0, 0});
            intersection.push_back(mINF);
        }
        ld cross(pll a, pll b){
            return (ld)(b.second - a.second) / (a.first - b.first);
        }
        void add_line(pll nl){
            while(cvh.size() >= 2){
                if(cross(cvh[cvh.size()-2], nl) <= cross(cvh.back(), nl)) break;
                cvh.pop_back();
                intersection.pop_back();
            }
            intersection.push_back(cross(cvh.back(), nl));
            cvh.push_back(nl);
        }
        ll query(ll x){
            ll idx = lower_bound(intersection.begin(), intersection.end(), x) - intersection.begin();
            idx--;
            // if(cvh[idx].first * x + cvh[idx].second > 0){
            //     for(auto x: cvh) cout << x.first << ' ' << x.second << '\n';
            //     for(auto x: intersection) cout << x << ' ';
            //     cout << '\n';
            //     cout << "query: " << x << ' ' << cvh[idx].first << ' ' << cvh[idx].second << '\n';
            // }
            return cvh[idx].first * x + cvh[idx].second;
        }
    };
    vector<Node> tree;
    ll sz;
    void init(ll N){
        sz = 1;
        while(sz < N) sz <<= 1;
        tree.resize(2*sz, Node());
    }

    void update(ll i, pll nl){
        // cout << "update: " << i << ' ' << nl.first << ' ' << nl.second << '\n';
        ll idx = sz + i;
        while(idx){
            tree[idx].add_line(nl);
            idx >>= 1;
        }
    }
    ll query(ll L, ll R, ll x){
        ll left = L + sz, right = R + sz;
        ll ret = -1e16;
        while(left <= right){
            if((left&1)==1) ret = max(ret, tree[left++].query(x));
            if((right&1)==0) ret = max(ret, tree[right--].query(x));
            left >>= 1; right >>= 1;
        }
        // if(ret>0) cout << L << ' ' << R << ' ' << x << ' ' << ret << '\n';
        return ret;
    }
}ST;

const ll mxN = 2e5;
ll N;
ll A[mxN], DP[mxN];
vector<ll> newA;
map<ll, ll> mp;

void solve(){
    ifstream cin("D:\\Programming-D\\PS\\test\\input.txt");
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) newA.push_back(A[i]);
    sort(newA.begin(), newA.end());
    newA.erase(unique(newA.begin(), newA.end()), newA.end());
    rep(i, 0, newA.size()) mp[newA[i]] = i;
    ST.init(newA.size());
    fill(DP, DP+N+1, -1e18);
    DP[0] = 0;
    rep(i, 0, N){
        ll idx = mp[A[i]];
        DP[i+1] = ST.query(0, idx, i+1) + A[i] - i*(i+1)/2;
        if(DP[i+1]>0){
            cout << ST.query(0, idx, i+1) << ' ' << A[i] << ' ' << i*(i+1)/2 << '\n';
            cout << "i: " << i << " idx: " << idx << " query: " << ST.query(0, idx, i+1) << " " << DP[i+1] << '\n';
        }
        ST.update(idx, {i+1, DP[i+1]-(i+2)*(i+1)/2});
    }
    ll ans = -1e18;
    rep(i, 0, N+1){
        ll rest = N - i;
        ans = max(ans, DP[i] - rest*(rest+1)/2);
    }
    // rep(i, 0, N+1) cout << DP[i] << ' ';
    // cout << '\n';
    cout << ans << '\n';
    return;
}

int main(){
    fastio();
    ifstream cin("D:\\Programming-D\\PS\\test\\input.txt");
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}