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

int N;
vector<ll> A;
priority_queue<pll> pq;
bool used[200000];

void solve(){
    cin >> N;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];
    fill(used, used+N, false);
    ll sum = 0;
    rep(i, 0, N) pq.push({A[i], i});
    rep(i, 0, N/2){
        auto [a, idx] = pq.top(); pq.pop();
        used[idx] = true;
        sum += a;
    }
    // rep(i, 0, N) cout << used[i] << ' ';
    // cout << '\n';

    int ans = 0, cnt = 0, minus = 0;
    rep(i, 0, N/2){
        if(used[2*i]) cnt++;
        if(used[2*i+1]) cnt++;
        if(cnt - minus > i - ans + 1){
            ans = i+1;
            minus = cnt;
        }
    }
    cout << ans*2 << ' ' << sum << '\n';
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