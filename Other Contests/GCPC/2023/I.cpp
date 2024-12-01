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

int N, arr[200000];
set<int> st;


void solve(){ 
    cin >> N;
    rep(i, 0, N) cin >> arr[i];
    rep(i, 1, 1250000) st.insert(i);
    rep(i, 0, N) st.erase(arr[i]);

    int Q; cin >> Q;
    while(Q--){
        int x; cin >> x; x--;
        int ret = *st.lower_bound(arr[x]);
        cout << ret << '\n';
        st.erase(ret);
        st.insert(arr[x]);
        arr[x] = ret;
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