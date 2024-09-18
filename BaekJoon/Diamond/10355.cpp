#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")

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

const int sq = 650;
int N, Q, mxsq;
vector<int> lazy;
vector<vector<pii>> bucket;

void water(int s, int e){
    int lsq = s/sq, rsq = e/sq;
    // cout << "Water " << s << ' ' << e << ' ' << lsq << ' ' << rsq << '\n';

    if(lsq == rsq){
        for(auto &i: bucket[lsq]){
            if(s <= i.second && i.second <= e) i.first++;
        }
        sort(bucket[lsq].begin(), bucket[lsq].end());
        return;
    }

    for(auto &i: bucket[lsq]) if(s <= i.second && i.second <= e) i.first++;
    for(int B = lsq+1; B<rsq; B++) lazy[B]++;
    for(auto &i: bucket[rsq]) if(s <= i.second && i.second <= e) i.first++;
    sort(bucket[lsq].begin(), bucket[lsq].end());
    sort(bucket[rsq].begin(), bucket[rsq].end());
    // rep(i, 0, mxsq) cout << lazy[i] << ' '; cout << '\n';
}

int calc(int X){
    int ret = 0;
    rep(i, 0, mxsq){
        pii tmp = {X-lazy[i], 1e9};
        ret += (upper_bound(bucket[i].begin(), bucket[i].end(), tmp) - bucket[i].begin());
    }
    return ret;
}

void solve(){
    mxsq = N/sq+1;
    lazy.assign(mxsq, 0);
    bucket.assign(mxsq, vector<pii>());

    int mx = 0, mn = 1e9;
    rep(i, 0, N){
        int x; cin >> x;
        bucket[i/sq].push_back({x, i});

        mx = max(mx, x);
        mn = min(mn, x);
    }
    // cout << "Input end" << endl;
    rep(i, 0, mxsq) sort(bucket[i].begin(), bucket[i].end());
    mx += Q;

    int ok = 1e9+100000, ng = -1;
    while(ok - ng>1){
        int mid = (ok+ng)/2;
        // cout << mid << ' ' << calc(mid) << '\n';
        if(calc(mid) >= (N+1)/2) ok = mid;
        else ng = mid;
    }
    int ans = ok;
    while(Q--){
        int s, e; cin >> s >> e;
        s--; e--;
        water(s, e);
        if(calc(ans) < (N+1)/2) ans++;
        cout << ans << '\n';
    }
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(1){
        cin >> N >> Q;
        if(N == 0) break;
        solve();
    }
    return 0;
}