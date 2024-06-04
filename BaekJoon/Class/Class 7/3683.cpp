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

int C, D, V;
vector<pii> AS, BS;
int AM[500], BM[500];
vector<int> links[500];
bool visited[500];

bool dfs(int a){
    if(visited[a]) return false;
    visited[a] = true;
    for(auto nxt: links[a]){
        if(BM[nxt] == -1 || dfs(BM[nxt])){
            AM[a] = nxt;
            BM[nxt] = a;
            return true;
        }
    }
    return false;
}


void solve(){
    cin >> C >> D >> V;
    rep(i, 0, V){
        string a, b; cin >> a >> b;
        int ai = stoi(a.substr(1));
        int bi = stoi(b.substr(1));
        if(a[0] == 'C') AS.push_back({ai, bi});
        else BS.push_back({ai, bi});
    }
    rep(i, 0, AS.size()){
        rep(j, 0, BS.size()){
            pii A = AS[i], B = BS[j];
            if(A.first == B.second || A.second == B.first){
                links[i].push_back(j);
            }
        }
    }

    fill(AM, AM+500, -1);
    fill(BM, BM+500, -1);
    int ans = 0;
    rep(i, 0, AS.size()){
        if(AM[i] == -1){
            fill(visited, visited+500, false);
            if(dfs(i)) ans++;
        }
    }
    // rep(i, 0, AS.size()) cout << AM[i] << ' ';
    // cout << '\n';
    // rep(i, 0, BS.size()) cout << BM[i] << ' ';
    // cout << '\n';
    cout << V - ans << '\n';

    rep(i, 0, 500) links[i].clear();
    AS.clear();
    BS.clear();
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