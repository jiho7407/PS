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

int N, Q;
int lg2[50000];
int SpT[18][50000];

int query(int l, int r){
    int k = lg2[r-l];
    return max(SpT[k][l], SpT[k][r-(1<<k)]);
}

void solve(){ 
    lg2[1] = 0;
    rep(i, 2, 50000) lg2[i] = lg2[i/2]+1;

    cin >> N >> Q;
    rep(i, 0, N) cin >> SpT[0][i];
    rep(k, 1, 18) rep(i, 0, N-(1<<k)+1) SpT[k][i] = max(SpT[k-1][i], SpT[k-1][i+(1<<(k-1))]);

    int ans = 0;
    while(Q--){
        int A, B; cin >> A >> B;
        A--; B--;
        if(A == B) ans++;
        else if(A<B){
            if(SpT[0][A] >= query(A, B)) ans++;
        }
        else{
            if(SpT[0][A] >= query(B, A)) ans++;
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