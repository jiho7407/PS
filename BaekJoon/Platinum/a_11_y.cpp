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

const int mxN = 100000;
bitset<mxN> alp[26];

void solve(){
    int N; string S; cin >> S; N = S.size();
    rep(i, 0, N) alp[S[i]-'a'][i] = 1;

    int Q; cin >> Q;
    while(Q--){
        string T; cin >> T;
        int M = stoi(T.substr(1, T.size()-2));
        int a = T[0]-'a', b = T[T.size()-1]-'a';
        bitset<mxN> ret = (alp[a] << (M+1)) & alp[b];
        cout << ret.count() << '\n';
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