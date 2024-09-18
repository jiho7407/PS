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

ll N, B;
int A[5][5], ans[5][5];
int mod = 1000;

// a*b를 a에 저장하는 함수
void mularr(int a[5][5], int b[5][5]){
    int tmp[5][5];
    for(int i = 0; i<5; i++) fill(tmp[i], tmp[i]+5, 0);

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            for(int k = 0; k<N; k++){
                tmp[i][j] += a[i][k] * b[k][j];
                tmp[i][j] %= mod;
            }
        }
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            a[i][j] = tmp[i][j];
        }
    }
}

// a^b를 a에 저장하는 함수
void powarr(int a[5][5], ll b){
    int tmp[5][5];
    for(int i = 0; i<5; i++) fill(tmp[i], tmp[i]+5, 0);
    for(int i = 0; i<N; i++) tmp[i][i] = 1; // 단위행렬

    while(b){
        if(b%2) mularr(tmp, a); // tmp = tmp * a
        mularr(a, a); // a = a * a
        b /= 2;
    }

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            a[i][j] = tmp[i][j];
        }
    }
}

void solve(){
    cin >> N >> B;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> A[i][j];
        }
    }

    powarr(A, B);

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout << A[i][j] << ' ';
        }
        cout << '\n';
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