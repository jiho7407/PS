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

int N;
vector<int> A, B;
map<pii, ll> mp[3];

void solve(){
    cin >> N;
    A.resize(N);
    B.resize(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];

    mp[0][{A[0], B[0]}] = 1;
    mp[1][{B[0], A[0]}] = 1;

    rep(i, 1, N){
        map<pii, ll> tmp[3];
        for(auto [k, v]: mp[0]){
            auto [a, b] = k;
            tmp[0][{__gcd(a, A[i]), __gcd(b, B[i])}] += v;
            tmp[1][{__gcd(a, B[i]), __gcd(b, A[i])}] += v;
        }
        for(auto [k, v]: mp[1]){
            auto [a, b] = k;
            tmp[1][{__gcd(a, B[i]), __gcd(b, A[i])}] += v;
            tmp[2][{__gcd(a, A[i]), __gcd(b, B[i])}] += v;
        }
        for(auto [k, v]: mp[2]){
            auto [a, b] = k;
            tmp[2][{__gcd(a, A[i]), __gcd(b, B[i])}] += v;
        }
        rep(j, 0, 3) mp[j] = tmp[j];
    }
    ll mx = -1, cnt = 0;
    rep(i, 1, 3){
        for(auto [k, v]: mp[i]){
            auto [a, b] = k;
            if(a+b == mx) cnt += v;
            else if(a+b > mx){
                mx = a+b;
                cnt = v;
            }
        }
    }
    cout << mx << ' ' << cnt << '\n';

    rep(i, 0, 3) mp[i].clear();
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