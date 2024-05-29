#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 6e5;
int N, M;
int LA[mxN], RA[mxN];
int A[mxN], L[mxN], Mx[mxN]; // A: 수, L: LIS 최대길이, M: 해당 길이의 LIS의 최소 마지막값
bool used[mxN];

void track(int idx, int len){
    if(len == 0) return;
    if(L[idx] == len){
        used[A[idx]-1] = true;
        track(idx-1, len-1);
    }
    else track(idx-1, len);
}

void solve(){
    cin >> N >> M;
    rep(i, 1, N+2){
        LA[i] = i-1;
        RA[i] = i+1;
    }
    RA[0] = 1;
    LA[N+1] = N;
    while(M--){
        char q; cin >> q;
        int a ,b; cin >> a >> b;

        // a 삭제
        LA[RA[a]] = LA[a];
        RA[LA[a]] = RA[a];

        if(q == 'A'){ // a를 b의 왼쪽에 삽입
            RA[LA[b]] = a;
            RA[a] = b;
            LA[a] = LA[b];
            LA[b] = a;
        }
        else{ // a를 b의 오른쪽에 삽입
            LA[RA[b]] = a;
            LA[a] = b;
            RA[a] = RA[b];
            RA[b] = a;
        }
    }
    int cur = 0, idx = 0;
    while(RA[cur] != N+1){
        A[idx++] = RA[cur];
        cur = RA[cur];
    }

    int mxlen = 0;
    fill(L, L+N, 1);
    fill(Mx, Mx+N, 1e9);
    Mx[0] = A[0];
    rep(i, 1, N){
        int idx = lower_bound(Mx, Mx+N, A[i]) - Mx;
        L[i] = idx+1;
        Mx[idx] = min(Mx[idx], A[i]);
        mxlen = max(mxlen, L[i]);
    }
    fill(used, used+N, false);
    track(N-1, mxlen);
    int first;
    rep(i, 0, N){
        if(used[i]){
            first = i;
            break;
        }
    }
    cout << N-mxlen << '\n';
    if(!used[0]){
        cout << "A " << 1 << " " << first+1 << '\n';
    }
    rep(i, 1, N){
        if(!used[i]) cout << "B " << i+1 << " " << i << '\n';
    }
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