#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, M;
ll comb[50][50];

ll combination(ll n, ll r){
    if (comb[n][r] != 0) return comb[n][r];
    if(r == 0 || n == r) return 1;
    return comb[n][r] = combination(n-1, r-1) + combination(n-1, r);
}

ll calc(ll x){
    ll ret = 0;
    
    bitset<32> b(x);
    int idx = -1;
    for(int i = 0; i<32; i++) {if(b[i]) idx = i;};
    idx++;
    int cnt1 = b.count();
    for(int i = 0; i<idx; i++){
        if(cnt1 == 1) break;
        if(b[i]){
            cnt1--;
            for(int j = 0; j <= i; j++){
                if(cnt1 + j > idx/2) break;
                // cout << i << " " << j << "\n";
                ret += combination(i, j);
            }
        }
    }
    for(int i = 0; i<idx; i++){
        for(int j = 0; j<i; j++){
            if(j+1 > i/2) break;
            ret += combination(i-1, j);
        }
    }
    return ret;
}

void solve(){
    for(int i = 0; i<50; i++){
        fill(comb[i], comb[i]+50, 0);
        comb[i][0] = 1;
        comb[i][i] = 1;
    }
    cin >> N >> M;
    cout << calc(M+1) - calc(N) << "\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}