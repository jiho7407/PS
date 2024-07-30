#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

vector<int> idx;

void solve(){
    int N; string S;
    cin >> N >> S;

    idx.clear();
    for(int i = N-1; i>=0; i--){
        if(S[i] == '1' || S[i] == '?') idx.push_back(N-i-1);
    }
    if(idx.size() == 0) cout << 1 << ' ';
    else if(idx.size() == 1) cout << N + idx[0] << ' ';
    else cout << N + idx.back() + 1 << ' ';

    idx.clear();
    for(int i = N-1; i>=0; i--){
        if(S[i] == '1') idx.push_back(N-i-1);
    }
    if(idx.size() == 0) cout << 1 << '\n';
    else if(idx.size() == 1) cout << N + idx[0] << '\n';
    else cout << N + idx.back() + 1 << '\n';
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