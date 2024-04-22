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

struct Bus{
    ll s, e, idx;
    bool operator<(Bus &b) {
        if(s == b.s) return e > b.e;
        return s < b.s;
    }
};

ll N, M;
vector<Bus> busA, busB;
bool pos[500010];

void solve(){
    cin >> N >> M;
    rep(i, 1, M+1){
        ll a, b;
        cin >> a >> b;
        if(a < b) busA.push_back({a, b, i});
        else busB.push_back({a, b+N, i});
    }
    sort(busA.begin(), busA.end());
    sort(busB.begin(), busB.end());
    fill(pos, pos+M+1, false);
    ll mxE = -1;
    for(auto &b : busA){
        if(b.e <= mxE) continue;
        mxE = b.e;
        pos[b.idx] = true;
    }
    mxE = -1;
    for(auto &b : busB){
        if(b.e <= mxE) continue;
        mxE = b.e;
        pos[b.idx] = true;
    }
    if(busB.empty()){
        rep(i, 1, M+1) if(pos[i]) cout << i << ' ';
        return;
    }
    ll mnS = busB[0].s;
    rep(i, 0, busA.size()){
        if(!pos[busA[i].idx]) continue;
        if(busA[i].s >= mnS) pos[busA[i].idx] = false;
        if(busA[i].e <= (mxE - N)) pos[busA[i].idx] = false;
    }
    rep(i, 1, M+1) if(pos[i]) cout << i << ' ';
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