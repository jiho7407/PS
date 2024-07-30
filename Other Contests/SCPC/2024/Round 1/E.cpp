#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef tuple<int, int, int> tii;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 50500;
int N, Q, cnt, sq;
int A[mxN], ans[mxN], square[mxN+1];
tii query[mxN];
int mp[mxN+1];

bool cmp(tii a, tii b){
    auto [aL, aR, aidx] = a;
    auto [bL, bR, bidx] = b;
    if(aL/sq == bL/sq) return aR < bR;
    return aL/sq < bL/sq;
}

void add(int val){
    if(val == 1) return;
    if(val > mxN) return;
    while(1){
        mp[val]++;
        if(mp[val] != val) return;
        cnt++;
        mp[val] = 0;
        if(val >= 224) return;
        val = square[val];
    }
}

void remove(int val){
    if(val == 1) return;
    if(val > mxN) return;
    while(1){
        if(val > mxN) return;
        mp[val]--;
        if(mp[val] != -1) return;
        cnt--;
        mp[val] = val-1;
        if(val > 224) return;
        val = square[val];
    }
}

void solve(){
    cin >> N;
    sq = sqrt(N);
    rep(i, 0, N) cin >> A[i];
    cin >> Q;
    rep(i, 0, Q){
        int a, b; cin >> a >> b;
        a--; b--;
        query[i] = {a, b, i};
    }
    sort(query, query+Q, cmp);
    
    fill(mp, mp+mxN+1, 0);
    cnt = 0;
    int L = 0, R = -1;
    rep(i, 0, Q){
        auto [a, b, idx] = query[i];
        while(L > a) add(A[--L]);
        while(R < b) add(A[++R]);
        while(L < a) remove(A[L++]);
        while(R > b) remove(A[R--]);
        ans[idx] = cnt;
    }
    rep(i, 0, Q) cout << ans[i] << '\n';
}

int main(){
    fastio();
    rep(i, 0, mxN+1) square[i] = i*i;
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
    }
    return 0;
}