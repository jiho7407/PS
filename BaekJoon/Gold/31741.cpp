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

int N, S, E;
vector<int> Slines, Elines;
vector<pii> Mlines;

void solve(){
    cin >> N >> S >> E;
    rep(i,0,N){
        int s, e; cin >> s >> e;
        if(e < S) continue;
        if(s > E) continue;
        if(s <= S && E <= e){ // 선분 한개로 덮이는 경우
            cout << 0;
            return;
        }
        if(s <= S) Slines.push_back(e);
        else if(E <= e) Elines.push_back(s);
        else Mlines.push_back({s, e});
    }
    sort(Slines.begin(), Slines.end());
    sort(Elines.begin(), Elines.end());
    int ans = INT_MAX;
    for(auto e: Slines){ // 선분 두개로 덮이는 경우
        auto it = upper_bound(Elines.begin(), Elines.end(), e) - Elines.begin() - 1; // E를 지나는 선분의 시작점으로 이분탐색
        if(it == -1) continue;
        ans = min(ans, e - Elines[it]);
    }
    for(auto [s, e]: Mlines){ // 선분 세개로 덮이는 경우
        int ret = 0;
        auto it = lower_bound(Slines.begin(), Slines.end(), s) - Slines.begin(); // S를 지나는 선분의 끝점으로 이분탐색
        if(it == Slines.size()) continue;
        ret += Slines[it] - s;
        it = upper_bound(Elines.begin(), Elines.end(), e) - Elines.begin() - 1; // E를 지나는 선분의 시작점으로 이분탐색
        if(it == -1) continue;
        ret += e - Elines[it];
        ans = min(ans, ret);
    }
    if(ans == INT_MAX) cout << -1;
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