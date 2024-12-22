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
    string S, T; cin >> S >> T;
    int N, M; N = S.size(); M = T.size();
    if(N == 1 || M == 1){
        cout << -1;
        return;
    }
    vector<int> idx[26];
    rep(i, 1, N){
        idx[S[i]-'a'].push_back(i);
    }
    int mn = 1e9;
    pii ans;
    for(int i = M-2; i>=0; i--){
        int j = T[i] - 'a';
        if(!idx[j].empty()){
            int ret = idx[j][0] + (M - i);
            if(ret < mn){
                mn = ret;
                ans = make_pair(idx[j][0], M-i);
            }
        }
    }
    if(mn == 1e9) cout << -1;
    else cout << S.substr(0, ans.first) <<  T.substr(M-ans.second, ans.second);
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