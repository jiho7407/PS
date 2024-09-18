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

int N, Q;
vector<ll> A, B;

int cnt(int aidx, int bidx, ll taste){
    ll ret = 0;
    int ok, ng;

    // A[0:aidx) 에서 taste 이하인 수의 개수
    ok = aidx, ng = -1;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(A[mid] <= taste) ng = mid;
        else ok = mid;
    }
    ret += ok;

    // B[0:bidx) 에서 taste 이하인 수의 개수
    ok = bidx, ng = -1;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(B[mid] <= taste) ng = mid;
        else ok = mid;
    }
    ret += ok;

    return ret;
}

pii find(int taste){
    int aidx = lower_bound(A.begin(), A.end(), taste) - A.begin();
    int bidx = lower_bound(B.begin(), B.end(), taste) - B.begin();

    if(A[aidx] == taste) return {1, aidx+1};
    if(B[bidx] == taste) return {2, bidx+1};
}

void solve(){
    cin >> N; A.resize(N); B.resize(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    cin >> Q;
    while(Q--){
        int i, j, k; cin >> i >> j >> k;
        ll ok = 1LL<<32, ng = 0;
        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;
            if(cnt(i, j, mid) >= k) ok = mid;
            else ng = mid;
        }

        pii ans = find(ok);
        cout << ans.first << " " << ans.second << "\n";
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