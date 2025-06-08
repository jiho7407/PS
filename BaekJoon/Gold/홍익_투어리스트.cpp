/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, r, l) for(int i = r-1; i >= l; i--)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, Q;
bool flag[500000];
set<int> st;

void solve(){
    cin >> N >> Q;
    rep(i, 0, N){
        cin >> flag[i];
        if(flag[i]) st.insert(i);
    }
    int cur = 0;
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            int x; cin >> x; x--;
            if(flag[x]) st.erase(x);
            else st.insert(x);
            flag[x] ^= 1;
        }
        if(op == 2){
            int x; cin >> x;
            cur = (cur + x) % N;
        }
        if(op == 3){
            if(st.empty()) cout << -1 << '\n';
            else{
                auto it = st.lower_bound(cur);
                if(it == st.end()) it = st.begin();
                cout << (*it + N - cur) % N << '\n';
            }
            
        }
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