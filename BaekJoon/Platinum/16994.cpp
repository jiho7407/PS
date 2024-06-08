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

int Q;
char S[100010];
rope<char> Rope;

void solve(){
    cin >> S;
    Rope.insert(0, S);
    cin >> Q;
    while(Q--){
        int op; cin >> op;
        if(op == 1){
            int x, y; cin >> x >> y;
            rope<char> tmp = Rope.substr(x, y-x+1);
            Rope.erase(x, y-x+1);
            Rope.insert(0, tmp);
        }
        else if(op == 2){
            int x, y; cin >> x >> y;
            rope<char> tmp = Rope.substr(x, y-x+1);
            Rope.erase(x, y-x+1);
            Rope.insert(Rope.length(), tmp);
        }
        else{
            int x; cin >> x;
            cout << Rope[x] << '\n';
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