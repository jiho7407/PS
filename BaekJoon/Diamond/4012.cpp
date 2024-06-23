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

int N;
vector<tuple<int, int, int>> lst; // {start, end, idx};

bool cmp1(tuple<int, int, int> a, tuple<int, int, int> b){
    return get<1>(a) < get<1>(b);
}

void solve(){
    cin >> N;
    rep(i, 0, N){
        int s, e; cin >> s >> e;
        lst.push_back({s, e, i});
    }
    sort(lst.begin(), lst.end(), cmp1);

    int cnt = 0;
    int end = 0;
    vector<int> ans;
    rep(i, 0, N){
        auto [s, e, idx] = lst[i];
        if(end < s){
            cnt++;
            end = e;
            ans.push_back(idx);
        }
    }
    cout << cnt << '\n';
    for(auto x : ans) cout << x+1 << ' ';
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