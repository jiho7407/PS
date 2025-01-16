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

const int sq = 500;
struct Query{
    int idx, l, r;

    Query(int idx, int l, int r): idx(idx), l(l), r(r){}

    bool operator<(const Query &q) const{
        if(l/sq == q.l/sq) return r < q.r;
        return l/sq < q.l/sq;
    }
};

int N, M, cnt;
int A[200000], ans[200000];
vector<Query> Q;

void solve(){
    cin >> N >> M;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, M){
        int L, R; cin >> L >> R;
        L--; R--;
        Q.push_back(Query(i, L, R));
    }
    sort(Q.begin(), Q.end());

    cnt = 0;
    int lp = 0, rp = -1;
    for(auto [idx, l, r]: Q){
        while(l < lp){
            lp--;
            if((cnt+1)*2 > (rp - lp + 1)) continue;
            if(A[lp]*2 <= A[rp-cnt]) cnt++;
        }
        while(rp < r){
            rp++;
            if((cnt+1)*2 > (rp - lp + 1)) continue;
            if(A[lp+cnt]*2 <= A[rp]) cnt++;
        }
        while(lp < l){
            
        }
        while(r < rp) Minus(lp, rp--, 0);
        ans[idx] = cnt;
    }
    rep(i, 0, M) cout << ans[i] << '\n';
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