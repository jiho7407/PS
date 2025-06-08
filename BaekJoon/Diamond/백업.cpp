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
int N, K;
int A[100000], diff[100000];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
tuple<int, int, int> cur[100000];
set<tuple<int, int, int>> st;

void solve(){
    cin >> N >> K;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N-1) diff[i] = A[i+1] - A[i];
    rep(i, 0, N-1){
        pq.push({diff[i], i, i});
        cur[i] = {diff[i], i, i};
    }
    // rep(i, 0, N-1) cout << diff[i] << ' ';
    // cout << '\n';
    int ans = 0;
    while(K--){
        while(st.count(pq.top())) pq.pop();
        auto [w, a, b] = pq.top(); pq.pop();
        // cout << w << ' ' << a << ' ' << b << '\n';
        ans += w;
        tuple<int, int, int> nxt;
        if(a > 0 && b < N-2){
            auto [w1, a1, b1] = cur[a-1];
            auto [w2, a2, b2] = cur[b+1];
            nxt = {w1 + w2 - w, a1, b2};
            st.insert(cur[a1]);
            st.insert(cur[b2]);
            cur[a1] = cur[b2] = nxt;
            pq.push(nxt);
        }
        else if(a == 0){
            auto [w2, a2, b2] = cur[b+1];
            nxt = {2e9, a, b2};
            st.insert(cur[b2]);
            cur[b2] = nxt;
            pq.push(nxt);
        }
        else if(b == N-2){
            auto [w1, a1, b1] = cur[a-1];
            nxt = {2e9, a1, b};
            st.insert(cur[a1]);
            cur[a1] = nxt;
            pq.push(nxt);
        }
        auto [ww, aa, bb] = nxt;
        // cout << "nxt: " << ww << ' ' << aa << ' ' << bb << '\n';
    }
    cout << ans << '\n';
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