#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll mxN = 5e6;
struct Manacher{
    string S;
    ll N, r = 0, p = 0;
    ll A[mxN];
    Manacher(string T){
        S = "#";
        for(auto c : T){ S += c; S += '#'; }
        N = S.size();
        rep(i, 0, N){
            if(i <= r) A[i] = min(A[2*p-i], r-i);
            else A[i] = 0;

            while(1){
                if(i-A[i]-1 < 0 || i+A[i]+1 >= N) break; // 범위 밖으로 나간 경우
                if(S[i-A[i]-1] != S[i+A[i]+1]) break; // 대칭이 아닌 경우
                A[i]++;
            }

            if(r < i+A[i]){
                r = i+A[i];
                p = i;
            }
        }
    }
};

string S;
ll N, Q;
ll ans[mxN];

void solve(){
    cin >> S;
    auto MNC = new Manacher(S);
    cin >> Q;
    fill(ans, ans+mxN, 0);
    rep(i, 0, MNC->N){
        ll rad = MNC->A[i];
        ans[i-rad]++;
        ans[i+1] -= 2;
        ans[i+rad+2]++;
    }
    rep(i, 0, MNC->N-1) ans[i+1] += ans[i];
    rep(i, 0, MNC->N-1) ans[i+1] += ans[i];
    while(Q--){
        ll x; cin >> x;
        cout << ans[2*x-1]/2 << '\n';
    }
    return;
}

int main(){
    fastio();
    ll tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}

