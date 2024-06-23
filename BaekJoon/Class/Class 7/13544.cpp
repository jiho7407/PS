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

int sq = 1100;
int N;
int A[100000];
vector<int> bucket[100];

int query(int s, int e, int k){
    int ret = 0;
    while(s%sq && s<=e) ret += (A[s++] > k);
    while(e%sq != sq-1 && s<=e) ret += (A[e--] > k);
    if(s > e) return ret;
    for(int i = s/sq; i <= e/sq; i++){
        ret += bucket[i].end() - upper_bound(bucket[i].begin(), bucket[i].end(), k);
    }
    return ret;
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N){
        bucket[i/sq].push_back(A[i]);
    }
    rep(i, 0, N/sq+1) sort(bucket[i].begin(), bucket[i].end());
    int M; cin >> M;
    int ans = 0;
    while(M--){
        int a, b, c; cin >> a >> b >> c;
        a ^= ans, b ^= ans, c ^= ans;
        a--, b--;
        ans = query(a, b, c);
        cout << ans << '\n';
    }
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