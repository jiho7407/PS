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

int N;
vector<int> links[200000];
int depth[200000];
map<int, int> mp[200000];
int ans = 0;

void dfs(int c, int p){
    int sz = 0;
    links[c].erase(remove(links[c].begin(), links[c].end(), p), links[c].end());

    for(auto nxt: links[c]){
        depth[nxt] = depth[c] + 1;
        dfs(nxt, c);
        sz++;
    }

    if(sz == 2){
        map<int, int> &a = mp[links[c][0]];
        map<int, int> &b = mp[links[c][1]];
        int amx = a.rbegin()->first;
        int bmx = b.rbegin()->first;
        if(amx > bmx) swap(a, b), swap(amx, bmx); // b가 더 깊음

        vector<int> tmp;
        for(auto it = b.rbegin(); it != b.rend(); it++){
            auto [k, v] = *it;
            if(k - amx <= 1) break;
            ans += v;
            tmp.push_back(k);
        }
        for(auto k: tmp) b.erase(k);

        if(a.size() < b.size()) swap(a, b); // a가 더 큼
        mp[c] = a;
        for(auto [k, v]: b) mp[c][k] += v; // 스몰 투 라지
    }
    else if(sz == 1){
        map<int, int> &a = mp[links[c][0]];

        vector<int> tmp;
        for(auto it = a.rbegin(); it != a.rend(); it++){
            auto [k, v] = *it;
            if(k - depth[c] <= 1) break;
            ans += v;
            tmp.push_back(k);
        }
        for(auto k: tmp) a.erase(k);

        mp[c] = a;
    }

    mp[c][depth[c]]++;
}


void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int a, b; cin >> a >> b; a--; b--;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    dfs(0, -1);
    cout << ans << '\n';
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