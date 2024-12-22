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

void solve(){
    ll N, K; cin >> N >> K;
    string S; cin >> S;
    vector<ll> pf0, pf1, pfm;
    pf0.push_back(0);
    pf1.push_back(0);
    rep(i, 0, N){
        pf0.push_back(pf0.back() + (S[i] == '0'));
        pf1.push_back(pf1.back() + (S[i] == '1'));
    }
    rep(i, 0, N+1){
        pfm.push_back(pf1[i] - pf0[i]);
    }

    priority_queue<ll> pq;
    rep(i, 1, N+1){
        pq.push(pfm[N] - pfm[i]);
    }
    ll ans = 1;
    while(!pq.empty() && pq.top() > 0 && K > 0){
        K -= pq.top();
        pq.pop();
        ans++;
    }

    if(K <= 0) cout << ans << "\n";
    else cout << -1 << "\n";
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