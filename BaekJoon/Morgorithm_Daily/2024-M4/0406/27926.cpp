#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, M;
tuple<ll, ll, ll> synergy[300000];
vector<pair<ll, ll>> links[200000];

bool cmp1(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b){
    return get<2>(a) > get<2>(b);
}

bool cmp2(pair<ll, ll> a, pair<ll, ll> b){
    return a.second > b.second;
}

ll calc(ll a, ll b, ll c){
    ll ret = c;
    ll d = -1, e = -1;
    for(auto [next, cost] : links[a]){
        if(next == b) continue;
        ret += cost;
        d = next;
        break;
    }
    for(auto [next, cost] : links[b]){
        if(next == a || next == d) continue;
        ret += cost;
        e = next;
        break;
    }
    return ret;
}

void solve(){
    cin >> N >> M;
    for(ll i = 0; i < M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        synergy[i] = {a, b, c};
        links[a].push_back({b, c});
        links[b].push_back({a, c});
    }
    if(M==0) {cout << 0; return;}
    if(M==1) {cout << get<2>(synergy[0]); return;}
    sort(synergy, synergy + M, cmp1);
    for (ll i = 0; i < N; i++){
        sort(links[i].begin(), links[i].end(), cmp2);
    }
    ll ans = get<2>(synergy[0]) + get<2>(synergy[1]);
    for(ll i = 0; i<M; i++){
        auto [a, b, c] = synergy[i];
        ans = max(ans, max(calc(a, b, c), calc(b, a, c)));
    }
    cout << ans;
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}