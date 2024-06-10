#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll V, E, Vlv, MSTcost;
vector<tii> edges;
vector<pll> links[50000];
ll root[50000], lv[50000];
ll par[50000][20];
ll mxcost1[50000][20], mxcost2[50000][20];


bool cmp(tii a, tii b){
    return get<2>(a) < get<2>(b);
}

ll findroot(ll a){
    if(root[a] == a) return a;
    return root[a] = findroot(root[a]);
}

bool merge(ll a, ll b){
    a = findroot(a);
    b = findroot(b);
    if(a == b) return false;
    if(a < b) root[b] = a;
    else root[a] = b;
    return true;
}

void maketree(ll cur, ll p){
    for(auto [nxt, cost]: links[cur]){
        if(nxt == p) continue;
        par[nxt][0] = cur;
        mxcost1[nxt][0] = cost;
        mxcost2[nxt][0] = -1e15;
        lv[nxt] = lv[cur] + 1;
        MSTcost += cost;
        maketree(nxt, cur);
    }
}

void makeMaxPair(ll &a, ll &b, vector<ll> &c){
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    if(c.size() >= 2){
        a = c[c.size()-1];
        b = c[c.size()-2];
    }
    else if(c.size() == 1){
        a = c[0];
        b = -1e15;
    }
    else{
        a = b = -1e15;
    }
}

void makeLCA(){
    rep(j, 1, Vlv){
        rep(i, 0, V){
            par[i][j] = par[par[i][j-1]][j-1];
            vector<ll> tmp = {mxcost1[i][j-1], mxcost2[i][j-1], mxcost1[par[i][j-1]][j-1], mxcost2[par[i][j-1]][j-1]};
            makeMaxPair(mxcost1[i][j], mxcost2[i][j], tmp);
        }
    }
}

pll getmax(ll a, ll b){
    ll max1 = -1e15, max2 = -1e15;
    if(a == b) return {max1, max2};
    if(lv[a] < lv[b]) swap(a, b);
    ll diff = lv[a] - lv[b];
    for(ll i=0; diff; i++){
        if(diff % 2){
            vector<ll> tmp = {max1, max2, mxcost1[a][i], mxcost2[a][i]};
            makeMaxPair(max1, max2, tmp);
            a = par[a][i];
        }
        diff /= 2;
    }
    if(a == b) return {max1, max2};
    for(ll i=Vlv-1; i>=0; i--){
        if(par[a][i] != par[b][i]){
            vector<ll> tmp = {max1, max2, mxcost1[a][i], mxcost2[a][i], mxcost1[b][i], mxcost2[b][i]};
            makeMaxPair(max1, max2, tmp);
            a = par[a][i];
            b = par[b][i];
        }
    }
    vector<ll> tmp = {max1, max2, mxcost1[a][0], mxcost2[a][0], mxcost1[b][0], mxcost2[b][0]};
    makeMaxPair(max1, max2, tmp);
    return {max1, max2};
}

void solve(){
    cin >> V >> E;
    Vlv = 1;
    while((1<<Vlv) <= V) Vlv++;
    rep(i, 0, E){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end(), cmp);
    ll cnt = 1;

    rep(i, 0, V) root[i] = i;

    ll edgeidx = 0;
    while(edgeidx<E && cnt<V){
        auto [a, b, c] = edges[edgeidx];
        if(merge(a, b)){
            links[a].push_back({b, c});
            links[b].push_back({a, c});
            cnt++;
        }
        edgeidx++;
    }

    if(cnt < V){ // 트리 만들기 실패
        cout << -1;
        return;
    }

    lv[0] = 0;
    maketree(0, -1);
    makeLCA();
    // rep(i, 0, V) cout << par[i][0] << ' ' << mncost[i][0] << '\n';

    ll ans = 1e9;
    for(auto [a, b, c]: edges){
        pll tmp = getmax(a, b);
        if(tmp.first == c) ans = min(ans, MSTcost - tmp.second + c);
        else ans = min(ans, MSTcost - tmp.first + c);
        // cout << a << ' ' << b << ' ' << c << ' ' << tmp.first << ' ' << tmp.second << ' ' << ans << '\n';
    }
    // cout << MSTcost << "\n";
    if(ans == 1e9) cout << -1;
    else cout << ans;
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