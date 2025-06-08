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

int N, M;
vector<int> links[200000];
bool visited[200000], used[200000];
vector<tuple<int, int, int>> ans;
map<int, int> origin;

struct UnionFind{
    vector<int> par, cnt;
    int group;

    void init(int N){
        par.resize(N);
        cnt.resize(N);
        rep(i, 0, N){
            par[i] = i;
            cnt[i] = 1;
        }
        group = N;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return false;
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
        group--;
        return true;
    }
}UF;

void dfs(int cur, int par){
    // cout << cur << ' ' << par << '\n';
    // cout << "child is ";
    // for(auto nxt: links[cur]) if(nxt != par) cout << nxt << ' ';
    // cout << '\n';
    visited[cur] = true;
    for(auto nxt: links[cur]) if(nxt != par) dfs(nxt, cur);
    vector<int> nxts;
    for(auto nxt: links[cur]) if(nxt != par && !used[nxt]) nxts.push_back(nxt);
    // cout << "cur nxts " << cur << ' ' << nxts.size() << '\n';
    for(int i = 0; i+1 < nxts.size(); i+=2){
        int a = nxts[i], b = nxts[i+1];
        ans.push_back({a, cur, b});
        used[a] = used[b] = true;
    }
    if(nxts.size()%2 == 1 && par != -1){
        int a = nxts.back(), b = par;
        ans.push_back({a, cur, b});
        used[a] = used[cur] = true;
    }
}

void solve(){
    cin >> N >> M;
    UF.init(N*2);
    int idx = N;
    rep(i, 0, M){
        int a, b; cin >> a >> b;
        a--; b--;
        if(UF.merge(a, b)){
            links[a].push_back(b);
            links[b].push_back(a);
        }
        else{
            origin[idx] = b;
            b = idx++;
            links[a].push_back(b);
            links[b].push_back(a);
        }
    }

    rep(i, 0, N) if(!visited[i]) dfs(i, -1);
    cout << ans.size() << '\n';
    for(auto [a, b, c] : ans){
        if(a >= N) a = origin[a];
        if(b >= N) b = origin[b];
        if(c >= N) c = origin[c];
        cout << a+1 << ' ' << b+1 << ' ' << c+1 << '\n';
    }
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