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
int A[5000];

struct Fenwick{
    vector<ll> tree;
    Fenwick(int n){
        tree.resize(n+1);
    }

    void init(int n){
        tree.assign(n+1, 0);
    }

    void update(int idx, ll diff){
        while(idx < tree.size()){
            tree[idx] += diff;
            idx += (idx & -idx);
        }
    }
    ll query(int idx){
        ll ret = 0;
        while(idx > 0){
            ret += tree[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }
};

Fenwick pfst(5000), sfst(5000);

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];

    ll ans = 0;
    rep(i, 0, N){
        pfst.init(N);
        sfst.init(N);
        int cnt = 0;
        rep(j, i+2, N) sfst.update(A[j], 1);
        rep(j, i+2, N){
            sfst.update(A[j], -1);
            cnt += sfst.query(A[j-1]);
            cnt -= (pfst.query(N) - pfst.query(A[j]));
            pfst.update(A[j-1], 1);
            if(A[i] < A[j]) ans += cnt;
        }
    }
    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}