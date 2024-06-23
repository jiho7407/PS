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

int N, S;
vector<int> A, pfsum;
vector<int> ans;

bool check(int idx, int sz){
    if(idx+sz+1 > N) return false;
    if(idx-sz+1 < 0) return false;
    bool flag1 = pfsum[idx+sz+1] - pfsum[idx+1] <= S;
    bool flag2 = pfsum[idx+1] - pfsum[idx-sz+1] <= S;
    return flag1 && flag2;
}

void solve(){
    cin >> N >> S;
    A.resize(N); pfsum.resize(N+1, 0);
    rep(i, 0, N) cin >> A[i];
    rep(i, 1, N+1) pfsum[i] = pfsum[i-1] + A[i-1];
    ans.resize(N, 0);
    rep(i, 0, N){
        int ok = 0, ng = N;
        while(ng-ok > 1){
            int mid = (ok+ng)/2;
            if(check(i, mid)) ok = mid;
            else ng = mid;
        }
        ans[i - ok + 1] = max(ans[i - ok + 1], ok);
    }
    rep(i, 1, N) ans[i] = max(ans[i], ans[i-1]-1);
    rep(i, 0, N) cout << ans[i]*2 << '\n';
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