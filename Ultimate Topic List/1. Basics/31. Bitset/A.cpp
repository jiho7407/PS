#include <iostream>
#include <algorithm>
#include <bitset>
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
bitset<1000> C[10000], ret;

void solve(){
    cin >> N;
    rep(i, 0, N){
        int cnt; cin >> cnt;
        while(cnt--){
            int x; cin >> x; x--;
            C[x].set(i);
        }
    }
    cin >> Q;
    while(Q--){
        int a, b; cin >> a >> b; a--; b--;
        ret = C[a] & C[b];
        if(ret.any()) cout << "Yes\n";
        else cout << "No\n";
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