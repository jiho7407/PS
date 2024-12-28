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

ll N, K;
vector<ll> A;
bool flip = false;
ll allXOR = 0;
ll ans = -1e18;

vector<int> idxs;

void btr(ll idx, ll cnt){
    if(N - idx < K - cnt) return;
    if(cnt == K){
        ll ret = 0;
        for(auto i : idxs) ret ^= A[i];
        if(flip) ret = allXOR ^ ret;
        ans = max(ans, ret);
        return;
    }

    idxs.push_back(idx);
    btr(idx+1, cnt+1);
    idxs.pop_back();
    btr(idx+1, cnt);
}

void solve(){
    cin >> N >> K;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) allXOR ^= A[i];

    if(K > N-K) K = N-K, flip = true;

    btr(0, 0);
    cout << ans;
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