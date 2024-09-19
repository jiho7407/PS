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

map<string, int> mp;
pii goal;
int sidx = 0;
int N, M;
vector<pii> document[1000];
vector<int> from[300][300];
bool used[1000];
bool chk[300][300];

string S1, S2;

void dfs(int a, int b){
    chk[a][b] = true;
    for(auto i: from[a][b]){
        if(used[i]) continue;
        used[i] = true;
        for(auto [a, b]: document[i]){
            if(chk[a][b]) continue;
            dfs(a, b);
        }
    }
}

void solve(){
    cin >> S1 >> S2;
    mp[S1] = sidx++;
    mp[S2] = sidx++;
    goal = {mp[S1], mp[S2]};
    cin >> N;
    rep(i, 0, N){
        cin >> M;
        while(M--){
            string S1, S2; cin >> S1 >> S2;
            if(mp.find(S1) == mp.end()) mp[S1] = sidx++;
            if(mp.find(S2) == mp.end()) mp[S2] = sidx++;
            document[i].push_back({mp[S1], mp[S2]});
        }
    }

    rep(i, 0, N){
        for(auto [a, b]: document[i]){
            from[a][b].push_back(i);
        }
    }

    dfs(goal.first, goal.second);
    rep(k, 0, sidx) rep(i, 0, sidx) rep(j, 0, sidx){
        if(chk[i][k] && chk[k][j]) chk[i][j] = true;
    }

    bool ok = true;
    rep(i, 0, sidx) if(chk[i][i]) ok = false;

    rep(i, 0, N) if(!used[i]) for(auto [a, b]: document[i]) if(chk[a][b]) ok = false;

    cout << (ok ? "Yes" : "No");
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