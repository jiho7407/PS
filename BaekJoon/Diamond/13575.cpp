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

// FFT
const double PI = acos(-1);
typedef complex<double> cpd;

//비재귀 FFT https://blog.myungwoo.kr/54, https://blog.naver.com/kks227/221633584963 참조.. 
void FFT(vector<cpd> &A, bool ivt){
    int N = A.size();

    // 비트 반전순서로 재배치 -> 띄엄띄엄 참조하지 않아 더 빨라짐!
    int j = 0;
    for(int i = 1; i < N; i++){
        int bit = N >> 1;
        while(j>=bit){
            j -= bit;
            bit >>= 1;
        }
        j += bit;
        if (i < j) swap(A[i], A[j]);
    }

    // FFT 수행
    for(int len = 2; len<= N; len <<= 1){
        double th = 2*PI/len;
        if(ivt) th *= -1;
        cpd w_unit(cos(th), sin(th));
        for(int i = 0; i<N; i+=len){
            cpd w = cpd(1, 0);
            for(int j = 0; j<len/2; j++){
                cpd u = A[i+j]; // 짝수부
                cpd v = A[i+j+len/2]*w; // 홀수부
                A[i+j] = u+v;
                A[i+j+len/2] = u-v;
                w *= w_unit;
                // 0-1 2-3 4-5 6-7 / 0-2 1-3 4-6 5-7 / 0-4 1-5 2-6 3-7...
                // 원래 숫자는 1-5 3-7 2-6 4-8 / ...
            }
        }
    }

    if(ivt){
        for(int i = 0; i<N; i++) A[i] /= N;
    }
}

void mul(vector<cpd> &A, vector<cpd> &B){
    int N = 1;
    while(N < A.size() + B.size()) N <<= 1;
    A.resize(N); B.resize(N);
    FFT(A, false); FFT(B, false);
    for(int i = 0; i<N; i++) A[i] *= B[i];
    FFT(A, true);
}

ll N, M;
vector<cpd> A, B;

void solve(){
    cin >> N >> M;
    A.resize(1);
    B.resize(N + 1);
    A[0] = cpd{1, 0};
    rep(i, 0, N){
        int x; cin >> x;
        B[x] = cpd{1, 0};
    }
    rep(i, 0, M){
        mul(A, B);
    }
    rep(i, 0, A.size()) cout << (ll)(A[i].real()+0.5) << ' ';
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