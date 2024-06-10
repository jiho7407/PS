#pragma GCC optimize("Ofast")
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

int N, M;
int sq = 1200, sz;
vector<int> bucket[105];
int arr[100010];

void build(){
    rep(i, 0, N){
        bucket[i/sq].push_back(arr[i]);
    }
    rep(i, 0, N/sq){
        sort(bucket[i].begin(), bucket[i].end());
    }
    return;
}

void update(int idx, int val){
    int bidx = idx/sq;
    auto it = upper_bound(bucket[bidx].begin(), bucket[bidx].end(), arr[idx]);
    bucket[bidx].erase(it);

    arr[idx] = val;

    it = upper_bound(bucket[bidx].begin(), bucket[bidx].end(), val);
    bucket[bidx].insert(it, val);
    // rep(i, 0, N/sq){
    //     for(auto x: bucket[i]) cout << x << ' ';
    //     cout << '\n';
    // }
    return;
}

int query(int L, int R, int val){
    int ret = 0;
    while(L%sq != 0 && L <= R) if(arr[L++] > val) ret++;
    while(R%sq != sq-1 && L <= R) if(arr[R--] > val) ret++;
    // cout << L << ' ' << R << ' ' << val << ' ' << ret << '\n';
    int stbidx = L/sq;
    while(L <= R){
        ret += bucket[stbidx].end() - upper_bound(bucket[stbidx].begin(), bucket[stbidx].end(), val);
        L += sq;
        stbidx++;
    }
    // cout << L << ' ' << R << ' ' << val << ' ' << ret << '\n';
    return ret;
}



void solve(){
    cin >> N;
    rep(i, 0, N) cin >> arr[i];
    build();
    cin >> M;
    while(M--){
        int op; cin >> op;
        if(op == 1) {
            int idx, val; cin >> idx >> val;
            update(idx-1, val);
        }
        else{
            int L, R, val; cin >> L >> R >> val;
            cout << query(L-1, R-1, val) << '\n';
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