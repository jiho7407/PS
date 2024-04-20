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

const int mxN = 2e5+10;
int N, A[mxN];
int seg[4*mxN], cnt[4*mxN]; // 선분개수, 양수개수
vector<int> idxs[mxN];
vector<tuple<int, bool, int, int>> Q; // [idx, isStart, l, r]

bool cmp(tuple<int, bool, int, int> a, tuple<int, bool, int, int> b){
    if(get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
    return get<0>(a) < get<0>(b);
}

void update(int node, int l, int r, int s, int e, int val){
    if(e < l || r < s) return;
    if(s <= l && r <= e) seg[node] += val;
    else{
        int m = (l+r)/2;
        update(node*2, l, m, s, e, val);
        update(node*2+1, m+1, r, s, e, val);
    }
    if(seg[node] > 0) cnt[node] = r-l+1;
    else cnt[node] = (l == r) ? 0 : cnt[node*2] + cnt[node*2+1];
}

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) idxs[A[i]].push_back(i);
    rep(i, 1, N+1){
        if(idxs[i].size() == 0) continue;
        for(int j = 0; j < idxs[i].size(); j++){
            int L, R;
            (j==0) ? L = 0 : L = idxs[i][j-1]+1;
            (j==idxs[i].size()-1) ? R = N-1 : R = idxs[i][j+1]-1;
            Q.push_back({L, 1, idxs[i][j], R});
            Q.push_back({idxs[i][j], 0, idxs[i][j], R});
        }
    }
    sort(Q.begin(), Q.end(), cmp);
    ll ans = 0, idx = 0;
    rep(i, 0, N){
        while(idx < Q.size() && get<0>(Q[idx]) == i && get<1>(Q[idx]) == 1){
            int L = get<2>(Q[idx]), R = get<3>(Q[idx]);
            update(1, 0, N-1, L, R, 1);
            idx++;
        }
        ans += cnt[1];
        while(idx < Q.size() && get<0>(Q[idx]) == i && get<1>(Q[idx]) == 0){
            int L = get<2>(Q[idx]), R = get<3>(Q[idx]);
            update(1, 0, N-1, L, R, -1);
            idx++;
        }
    }
    cout << ans << '\n';
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