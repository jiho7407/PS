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

int N, M;
vector<pll> human, mask;

struct cmp{ // pq의 비교함수는 구조체로 만들어야 함
    bool operator()(pll a, pll b){
        return a.second > b.second; // true일때 우선순위가 높다
    }
};
priority_queue<pll, vector<pll>, cmp> pq;

void solve(){
    cin >> N >> M;
    rep(i, 0, N){
        ll a, b; cin >> a >> b;
        human.push_back({a, b});
    }
    rep(i, 0, M){
        ll a, b; cin >> a >> b;
        mask.push_back({a, b});
    }
    sort(human.begin(), human.end());
    sort(mask.begin(), mask.end());

    int ans = 0;
    int pos = 0;
    for(auto [P, C]: mask){
        while(pos < N && human[pos].first <= P) pq.push(human[pos++]);
        while(!pq.empty() && C){
            auto [L, R] = pq.top(); pq.pop();
            if(P < L || R < P) continue;
            ans++; C--;
        }
    }
    cout << ans;
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