#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 300001;
int N, L;
int A[mxN], B[mxN];
int root[mxN];
int cnt[mxN];

int find(int x){
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(x > y) swap(x, y);
    root[y] = x;
    cnt[x] += cnt[y];
}


void solve(){
    cin >> N >> L;
    rep(i, 1, N+1) cin >> A[i] >> B[i];
    rep(i, 1, mxN) root[i] = i;
    fill(cnt, cnt+mxN, 1);
    rep(i, 1, N+1){
        merge(A[i], B[i]);
        if(cnt[find(A[i])] == 0){
            cout << "SMECE\n";
            continue;
        }
        cnt[find(A[i])]--;
        cout << "LADICA\n";
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