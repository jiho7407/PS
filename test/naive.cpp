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
string S[3];

void solve(){ 
    // 입력
    cin >> N >> Q;
    rep(i, 0, 3) cin >> S[i];


    // 쿼리
    while(Q--){
        int L, R; cin >> L >> R;
        assert(1 <= L && L <= R && R <= N);
        L--; R--;
        vector<string> v;
        rep(i, 0, 3) v.push_back(S[i].substr(L, R-L+1));
        sort(v.begin(), v.end());
        rep(i, 0, 3) S[i].replace(L, R-L+1, v[i]);
    }
    rep(i, 0, 3) cout << S[i] << '\n';
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