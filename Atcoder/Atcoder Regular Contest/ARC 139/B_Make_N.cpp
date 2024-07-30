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

ll N, A, B, X, Y, Z;

void solve(){
    cin >> N >> A >> B >> X >> Y >> Z;
    ll ans = N*X; // X만 이용
    ans = min(ans, (N/A)*Y + (N%A)*X); // X, Y만 이용
    ans = min(ans, (N/B)*Z + (N%B)*X); // X, Z만 이용
    set<ll> visited;
    rep(i, 0, N/A+1){ // X, Y, Z 같이 이용, Y 위주로
        ll Q = (N-i*A)/B, R = (N-i*A)%B;
        if(visited.count(R)) break;
        ans = min(ans, R*X + i*Y + Q*Z);
        visited.insert(R);
    }
    swap(A, B); swap(Y, Z); visited.clear();
    rep(i, 0, N/A+1){ // X, Y, Z 같이 이용, Z 위주로
        ll Q = (N-i*A)/B, R = (N-i*A)%B;
        if(visited.count(R)) break;
        ans = min(ans, R*X + i*Y + Q*Z);
        visited.insert(R);
    }
    cout << ans << '\n';
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