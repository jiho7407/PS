#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const ll mod = 1e9+7;
int N, M;
int od[2] = {-1, 1}, ed[3] = {-1, 0, 1};
ll oddmat[30][30], evenmat[30][30];
ll odevmat[30][30], ansmat[30][30];
ll temp[30][30];

void matmul(ll a[30][30], ll b[30][30]){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){
            temp[i][j] = 0;
            for(int k = 0; k<M; k++){
                temp[i][j] += a[i][k] * b[k][j];
                temp[i][j] %= mod;
            }
        }
    }
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){
            a[i][j] = temp[i][j];
        }
    }
}

void matpow(ll a[30][30], int n){
    while(n > 0){
        if(n%2 == 1){
            matmul(ansmat, a);
        }
        matmul(a, a);
        n /= 2;
    }
}

ll matsum(ll a[30][30]){
    ll ret = 0;
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){
            ret += a[i][j];
            ret %= mod;
        }
    }
    return ret;
}

void solve(){
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        fill(oddmat[i], oddmat[i]+M, 0);
        fill(evenmat[i], evenmat[i]+M, 0);
        for(int d = 0; d<2; d++){
            if(i+od[d] < 0 || i+od[d] >= M) continue;
            oddmat[i][i+od[d]] = 1;
        }
        for(int d = 0; d<3; d++){
            if(i+ed[d] < 0 || i+ed[d] >= M) continue;
            evenmat[i][i+ed[d]] = 1;
        }
    }
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){
            odevmat[i][j] = oddmat[i][j];
        }
    }
    matmul(odevmat, evenmat);

    if(N==1) {
        cout << M << "\n";
        return;
    }
    if(N==2){
        cout << matsum(oddmat) << "\n";
        return;
    }
    N--;
    for(int i = 0; i<M; i++){
        fill(ansmat[i], ansmat[i]+M, 0);
        ansmat[i][i] = 1;
    }
    matpow(odevmat, N/2);
    if(N%2 == 1){
        matmul(ansmat, oddmat);
    }
    cout << matsum(ansmat) << "\n";
    
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