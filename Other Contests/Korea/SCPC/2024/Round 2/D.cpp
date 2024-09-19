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
int A[50000];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    int mn = *min_element(A, A+N), mx = *max_element(A, A+N);

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
    vector<int> notmnmx;
    rep(i, 0, N){
        if(A[i] != mn && A[i] != mx) notmnmx.push_back(i);
    }
    
    // 가운데에 mn쿼리 치기
    if(mxcnt >= N/2){
        int inmncnt = 0, inmxcnt = 0;
        int l = 0, r = -1;
        while(l < N){
            if(!notmnmx.empty() && notmnmx[0] < l) break;
            while(r < N-1){
                if(A[r+1] == mx && mxcnt - (inmxcnt+1) < N/2) break;
                r++;
                if(A[r] == mn) inmncnt++;
                if(A[r] == mx) inmxcnt++;
            }
            if(inmncnt && (notmnmx.empty() || notmnmx.back() <= r)){
                cout << 1 << '\n';
                cout << 1 << ' ' << l+1 << ' ' << r+1 << '\n';
                return;
            }
            if(A[l] == mn) inmncnt--;
            if(A[l] == mx) inmxcnt--;
            l++;
        }
    }
    // 가운데에 mx쿼리 치기
    if(mncnt >= N/2){
        int inmncnt = 0, inmxcnt = 0;
        int l = 0, r = -1;
        while(l < N){
            if(!notmnmx.empty() && notmnmx[0] < l) break;
            while(r < N-1){
                if(A[r+1] == mn && mncnt - (inmncnt+1) < N/2) break;
                r++;
                if(A[r] == mn) inmncnt++;
                if(A[r] == mx) inmxcnt++;
            }
            if(inmxcnt && (notmnmx.empty() || notmnmx.back() <= r)){
                cout << 1 << '\n';
                cout << 2 << ' ' << l+1 << ' ' << r+1 << '\n';
                return;
            }
            if(A[l] == mn) inmncnt--;
            if(A[l] == mx) inmxcnt--;
            l++;
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
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
    }
    return 0;
}