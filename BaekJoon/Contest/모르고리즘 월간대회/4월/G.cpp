#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, S, E;
vector<pll> lines;

bool cmp(const pll &A, const pll &B){
    return A.second < B.second;
}

void solve(){
    cin >> N >> S >> E;
    rep(i, 0, N){
        int a, b; cin >> a >> b;
        lines.push_back({a, b});
    }
    sort(lines.begin(), lines.end(), cmp);
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