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
    ll N, M; cin >> N >> M;

    if(N < M){
        cout << -1 << '\n';
        return;
    }

    if(N == M){
        cout << 0 << '\n';
        return;
    }

    if(__builtin_popcountll(N) == 1){
        cout << -1 << '\n';
        return;
    }

    vector<int> bitsN, bitsM;
    for(int i = 62; i>=0; i--){
        if((N>>i)&1){
            bitsN.push_back(i);
        }
        if((M>>i)&1){
            bitsM.push_back(i);
        }
    }

    for(auto x: bitsM){
        if(bitsN[1] < x && x < bitsN[0]){
            cout << -1 << '\n';
            return;
        }
    }

    vector<ll> ans;
    ans.push_back(N);
    if(bitsN[1] >= bitsM[0]){
        ans.push_back((1LL<<bitsN[1]+1) - 1);
        if(ans.back() != M){
            ans.push_back(M);
        }
    }
    else{
        ans.push_back(M);
    }

    cout << ans.size() - 1 << '\n';
    for(auto x: ans) cout << x << ' ';
    cout << '\n';
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