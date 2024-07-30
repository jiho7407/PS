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

ifstream cinn("D:\\Programming-D\\PS\\test\\input.txt");
int N;
int A[50000];
int tmp[50000];
int mn, mx;

bool complete(){
    // 0회로 끝낼 수 있는 경우
    int mncnt = 0, mxcnt = 0;
    rep(i, 0, N){
        if(tmp[i] == mn) mncnt++;
        if(tmp[i] == mx) mxcnt++;
    }
    if(N%2){ // 홀수일때는 N/2, N/2+1
        if(min(mncnt, mxcnt) == N/2 && max(mncnt, mxcnt) == N/2+1){
            return true;
        }
    }
    else{ // 짝수일때는 N/2, N/2
        if(mncnt == N/2 && mxcnt == N/2){
            return true;
        }
    }
    return false;
}

void solve(){
    cinn >> N;
    rep(i, 0, N) cinn >> A[i];
    mn = *min_element(A, A+N), mx = *max_element(A, A+N);

    // 모두 같은 숫자인 경우
    if(mn == mx){
        cout << 0 << '\n';
        return;
    }

    // 0회로 끝낼 수 있는 경우
    int mncnt = 0, mxcnt = 0;
    rep(i, 0, N){
        if(A[i] == mn) mncnt++;
        if(A[i] == mx) mxcnt++;
    }
    if(N%2){ // 홀수일때는 N/2, N/2+1
        if(min(mncnt, mxcnt) == N/2 && max(mncnt, mxcnt) == N/2+1){
            cout << 0 << '\n';
            return;
        }
    }
    else{ // 짝수일때는 N/2, N/2
        if(mncnt == N/2 && mxcnt == N/2){
            cout << 0 << '\n';
            return;
        }
    }

    // 1회로 끝낼 수 있는 경우
    // 5 2 1 5 5 1 모양 어떻게 처리해야할까?
    // 나이브 버전
    rep(i, 0, N) for(int j = N-1; j >= i; j--){
        int tmn = 1e9, tmx = -1;
        rep(k, i, j+1){
            tmn = min(tmn, A[k]);
            tmx = max(tmx, A[k]);
        }
        // op 1
        rep(k, 0, N) tmp[k] = A[k];
        rep(k, i, j+1) tmp[k] = tmn;
        if(complete()){
            cout << 1 << '\n';
            cout << 1 << ' ' << i+1 << ' ' << j+1 << '\n';
            return;
        }

        // op 2
        rep(k, 0, N) tmp[k] = A[k];
        rep(k, i, j+1) tmp[k] = tmx;
        if(complete()){
            cout << 1 << '\n';
            cout << 2 << ' ' << i+1 << ' ' << j+1 << '\n';
            return;
        }
    }

    // 2회로 끝낼 수 있는 경우
    int mnidx = -1, mxidx = -1;
    rep(i, 0, N){
        if(A[i] == mn) mnidx = i;
        if(A[i] == mx) mxidx = i;
    }

    bool mnmx = (mnidx < mxidx);
    int idx1 = min(mnidx, mxidx), idx2 = max(mnidx, mxidx);
    
    cout << 2 << '\n';
    if(idx2 < N/2){ // 왼쪽에 몰려있는 경우
        cout << (mnmx? 2 : 1) << ' ' << idx2+1 << ' ' << N << '\n';
        cout << (mnmx? 1 : 2) << ' ' << 1 << ' ' << N/2 << '\n';
    }
    else if(N/2 <= idx1){ // 오른쪽에 몰려있는 경우
        cout << (mnmx? 1 : 2) << ' ' << 1 << ' ' << idx1+1 << '\n';
        cout << (mnmx? 2 : 1) << ' ' << N/2+1 << ' ' << N << '\n';
    }
    else{ // 양쪽으로 나눠진경우
        cout << (mnmx? 1 : 2) << ' ' << 1 << ' ' << N/2 << '\n';
        cout << (mnmx? 2 : 1) << ' ' << N/2+1 << ' ' << N << '\n';
    }
}

int main(){
    fastio();
    int tc = 1;
    cinn >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
    }
    return 0;
}