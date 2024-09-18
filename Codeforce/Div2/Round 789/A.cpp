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
    int N;
    cin >> N;
    int zcnt = 0;
    bool flag = false;
    set<int> st;
    rep(i, 0, N){
        int x; cin >> x;
        if(x == 0) zcnt++;
        if(st.find(x) != st.end()) flag = true;
        st.insert(x);
    }
    if(zcnt) cout << N - zcnt << '\n';
    else if(flag) cout << N << '\n';
    else cout << N+1 << '\n';;
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