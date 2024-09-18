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

const int mxN = 2e4+1;
int Q;
bitset<mxN> field[mxN];

void solve(){
    cin >> Q;
    while(Q--){
        char op; cin >> op;
        int x, y; cin >> x >> y;
        if(op == '+') field[x].set(y);
        else if(op == '-') field[x].reset(y);
        else if(op == 'v') cout << (field[x] | field[y]).count() << '\n';
        else if(op == '^') cout << (field[x] & field[y]).count() << '\n';
        else if(op == '!') cout << (field[x] ^ field[y]).count() << '\n';
        else if(op == '\\') cout << (field[x] & ~field[y]).count() << '\n';
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