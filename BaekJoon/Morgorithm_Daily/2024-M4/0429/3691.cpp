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

map<string, int> tp;
vector<pair<ll, ll>> items[1000];
int tpidx = 0;

void solve(){
    ll N, B; cin >> N >> B;
    tp.clear();
    rep(i, 0, 1000) items[i].clear();
    tpidx = 0;
    rep(i, 0, N){
        string type, name;
        ll price, quality;
        cin >> type >> name >> price >> quality;
        int typeint;
        if(tp.find(type) == tp.end()) tp[type] = tpidx++;
        typeint = tp[type];
        items[typeint].push_back({quality, price});
    }
    rep(i, 0, tpidx) sort(items[i].begin(), items[i].end());
    ll ok = 0, ng = 1e18+1;
    while(ng-ok > 1){
        ll mid = (ok+ng)/2;
        ll sum = 0;
        rep(i, 0, tpidx){
            ll minprice = 1e9+1;
            for(auto item : items[i]){
                if(item.first < mid) continue;
                minprice = min(minprice, item.second);
            }
            sum += minprice;
        }
        if(sum <= B) ok = mid;
        else ng = mid;
    }
    cout << ok << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}