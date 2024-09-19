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

int N, M;
string S, T;
ll alp1[26], alp2[26];
const ll P1 = 1e9+7, P2 = 1e9+9;
vector<pll> v;

bool found(pll X){
    pll tmp = *lower_bound(v.begin(), v.end(), X);
    // cout << tmp.first << ' ' << tmp.second << ' ' << X.first << ' ' << X.second << '\n';
    if(tmp == X) return true;
    return false;
}

void solve(){
    cin >> S >> T;
    N = S.size(); M = T.size();

    alp1[0] = 1; alp2[0] = 1;
    rep(i, 1, 26){
        alp1[i] = alp1[i-1]*2000%P1;
        alp2[i] = alp2[i-1]*2000%P2;
    }

    rep(i, 0, N){
        ll tmp1 = 0, tmp2 = 0;
        rep(j, i, N){
            tmp1 += alp1[S[j]-'a'];
            tmp2 += alp2[S[j]-'a'];
            tmp1 %= P1; tmp2 %= P2;
            v.push_back({tmp1, tmp2});
        }
    }
    sort(v.begin(), v.end());
    
    int ans = 0;
    rep(i, 0, M){
        ll tmp1 = 0, tmp2 = 0;
        rep(j, i, M){
            tmp1 += alp1[T[j]-'a'];
            tmp2 += alp2[T[j]-'a'];
            tmp1 %= P1; tmp2 %= P2;
            if(found({tmp1, tmp2})) ans = max(ans, j-i+1);
        }
    }

    cout << ans;
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