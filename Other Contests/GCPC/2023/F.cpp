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

int W, H;
int arr[200000];

void solve(){ 
    cin >> W >> H;
    rep(i, 0, W) cin >> arr[i];

    // 이미 H를 넘긴경우
    bool flag = false;
    rep(i, 0, W) if(arr[i] > H) flag = true;
    if(flag){
        cout << "impossible\n";
        return;
    }

    // 그리디하게 채우기
    flag = true;
    set<int> omx, emx;
    rep(i, 0, W){
        if(i%2){
        }
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