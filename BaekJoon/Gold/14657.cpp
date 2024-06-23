#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, T;
vector<pii> links[50000];
ll rad = 0, rada, radcost = 1e18;
ll mxcnt = 0, mncost = 1e18;

void getrad(ll c, ll p, ll d, ll cost){
    if(d > rad) rad = d, rada = c, radcost = cost;
    else if(d == rad && cost < radcost) radcost = cost, rada = c;
    for(auto [nxt, w]: links[c]){
        if(nxt == p) continue;
        getrad(nxt, c, d+1, cost+w);
    }
}


void maketree(ll c, ll p, ll d, ll cost){
    // cout << c << " " << p << " " << d << " " << cost << ' ' << mxcnt << ' ' << mncost << endl;
    if(d > mxcnt) mxcnt = d, mncost = cost;
    else if(d == mxcnt) mncost = min(mncost, cost);
    for(auto [nxt, w]: links[c]){
        if(nxt == p) continue;
        maketree(nxt, c, d+1, cost+w);
    }
}

void solve(){
    cin >> N >> T;
    rep(i, 0, N-1){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        links[a].push_back({b, c});
        links[b].push_back({a, c});
    }
    rad = 0;
    getrad(0, -1, 0, 0);

    maketree(rada, -1, 0, 0);
    cout << (mncost-1)/T + 1;
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