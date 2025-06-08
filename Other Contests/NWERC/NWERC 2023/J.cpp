#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
vector<tii> v; // 시작, 끝, 인덱스
int ans[200000];

bool cmp(tii a, tii b){
    if(get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
    return get<0>(a) < get<0>(b);
}


void solve(){
    cin >> N;
    rep(i, 0, N){
        int a, t; cin >> a >> t;
        v.push_back({a, a+t, i});
    }
    sort(v.begin(), v.end(), cmp);

    vector<int> lds;
    rep(i, 0, N){
        auto [s, e, idx] = v[i];
        int ok = 0, ng = lds.size() + 1;
        while(ng - ok > 1){
            int mid = (ok + ng) / 2;
            if(lds.empty() || lds[mid-1] >= e) ok = mid;
            else ng = mid;
        }
        if(ok == lds.size()) lds.push_back(e);
        else lds[ok] = e;
        ans[idx] = ok;
    }

    rep(i, 0, N) cout << ans[i] << ' ';
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