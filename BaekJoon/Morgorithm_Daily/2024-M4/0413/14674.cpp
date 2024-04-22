#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
vector<tuple<ll, ll, ll>> games;

bool cmp(tuple<ll, ll, ll> a, tuple<ll, ll, ll> b){ 
    if (get<2>(a)*get<1>(b) == get<2>(b)*get<1>(a)){
        if (get<1>(a) == get<1>(b)){
            return get<0>(a) < get<0>(b);
        }
        return get<1>(a) < get<1>(b);
    }
    return get<2>(a)*get<1>(b) > get<2>(b)*get<1>(a);
}

void solve(){
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        games.push_back({a, b, c});
    }
    sort(games.begin(), games.end(), cmp);
    for(int i = 0; i<M; i++){
        cout << get<0>(games[i]) << "\n";
    }
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