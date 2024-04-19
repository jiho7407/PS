#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 200010;
int N, Q;
int A[mxN], cnt[mxN];
priority_queue<int, vector<int>, greater<int>> pq;

void solve(){
    cin >> N >> Q;
    int mex = 0;
    fill(A, A + N, 0);
    fill(cnt, cnt+N+1, 0);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(A[i] <= N) cnt[A[i]]++;
        while(cnt[mex] > 0) mex++;
    }
    for(int i = 1; i <= N; i++){
        if(cnt[i] > 0) continue;
        pq.push(i);
    }

    for(int i = 0; i < Q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        if(A[x] <= N){
            cnt[A[x]]--;
            if(cnt[A[x]] == 0){
                pq.push(A[x]);
                mex = min(mex, A[x]);
            }
        }
        A[x] = y;
        if(A[x] <= N){
            cnt[A[x]]++;
            if(cnt[A[x]] == 1 && A[x] == mex){
                while(!pq.empty() && cnt[pq.top()] > 0) pq.pop();
                if(pq.empty()) mex = N+1;
                else mex = pq.top();
            }
        }
        cout << mex << '\n';
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