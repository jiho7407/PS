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

// AB x AC
ll ccw(pll a, pll b, pll c){
    pll ab = {b.first - a.first, b.second - a.second};
    pll ac = {c.first - a.first, c.second - a.second};
    ll ret = ab.first*ac.second - ab.second*ac.first;
    if(ret > 0) return 1;
    if(ret < 0) return -1;
    return 0;
}

int N;
pll P, Q;
vector<pair<pll, pll>> seg, As, Bs;


void solve(){ 
    cin >> P.first >> P.second >> Q.first >> Q.second;
    cin >> N;
    seg.clear();
    rep(i, 0, N){
        pll a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        // PQ와 AB의 기울기가 같으면 패스
        if((P.first - Q.first) * (a.second - b.second) == (P.second - Q.second) * (a.first - b.first)) continue;

        // AB가 P를 지나는지 확인
        bool flagP = (ccw(a, b, P) == 0 && min(a.first, b.first) <= P.first && P.first <= max(a.first, b.first));

        // AB가 Q를 지나는지 확인
        bool flagQ = (ccw(a, b, Q) == 0 && min(a.first, b.first) <= Q.first && Q.first <= max(a.first, b.first));

        if(!flagP && !flagQ) continue;

        if(flagP) As.push_back({a, b});
        else Bs.push_back({a, b});
    }


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