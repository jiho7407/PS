#include <bits/stdc++.h>
#include <ext/rope>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
using namespace __gnu_cxx;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, Q;
char S[300010];
crope R;

void solve(){
    cin >> N >> Q;
    cin >> S;
    R.insert(0, S);
    while(Q--){
        int op; cin >> op;
        if(op==1){
            char tmp; int idx; cin >> tmp >> idx;
            R.insert(idx-1, tmp);
        }
        else{
            int l, r; cin >> l >> r;
            cout << R.substr(l-1, r-l+1) << '\n';
            R.erase(l-1, r-l+1);
        }
    }
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