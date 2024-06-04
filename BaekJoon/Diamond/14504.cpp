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

int N, M, sq;
int A[100000];
vector<int> bucket[320];

int query(int l, int r, int k){
    int ret = 0;
    while(l <= r && l%sq != 0) if(k < A[l++]) ret++;
    while(l <= r && r%sq != sq-1) if(k < A[r--]) ret++;
    while(l<=r){
        int bidx = l/sq;
        ret += bucket[bidx].end() - upper_bound(bucket[bidx].begin(), bucket[bidx].end(), k);
        l += sq;
    }
    return ret;
}

void update(int idx, int x){
    int bidx = idx/sq;
    auto it = lower_bound(bucket[bidx].begin(), bucket[bidx].end(), A[idx]);
    *it = x;
    A[idx] = x;
    sort(bucket[bidx].begin(), bucket[bidx].end());
    return;
}



void solve(){
    cin >> N; sq = sqrt(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) bucket[i/sq].push_back(A[i]);
    rep(i, 0, N/sq+1) sort(bucket[i].begin(), bucket[i].end());
    cin >> M;
    while(M--){
        int op; cin >> op;
        if(op == 1){
            int i, j, k; cin >> i >> j >> k; i--; j--;
            cout << query(i, j, k) << '\n';
        }
        else{
            int i, x; cin >> i >> x; i--;
            update(i, x);
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