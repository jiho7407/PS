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

const int mxN = 100000;
int N;
int mxlen  = 0;
int A[mxN], B[mxN], L[mxN], Mx[mxN];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, N){
        L[A[i]] = i;
    }
    rep(i, 0, N){
        Mx[i] = L[B[i]];
    }
    vector<int> v;
    v.push_back(-1);
    rep(i, 0, N){
        if(v.back() < Mx[i]){
            v.push_back(Mx[i]);
        }else{
            auto it = lower_bound(v.begin(), v.end(), Mx[i]);
            *it = Mx[i];
        }
    }
    cout << v.size()-1 << '\n';
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