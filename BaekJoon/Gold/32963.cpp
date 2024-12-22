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
vector<int> T, S;

void solve(){
    cin >> N >> Q;
    T.resize(N); S.resize(N);
    rep(i, 0, N) cin >> T[i];
    rep(i, 0, N) cin >> S[i];
    vector<pii> v;
    rep(i, 0, N) v.push_back({T[i], S[i]});
    sort(v.begin(), v.end());
    rep(i, 0, N) T[i] = v[i].first, S[i] = v[i].second;

    vector<int> ans(N);
    int mx = S[N-1], cnt = 1;
    ans[N-1] = 1;
    for(int i = N-2; i>=0; i--){
        if(S[i] > mx){
            mx = S[i];
            cnt = 1;
        }
        else if(S[i] == mx) cnt++;
        ans[i] = cnt;
    }

    while(Q--){
        int k; cin >> k;
        int idx = lower_bound(T.begin(), T.end(), k) - T.begin();
        if(idx == N) cout << 0 << '\n';
        else cout << ans[idx] << '\n';
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