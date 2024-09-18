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

    void merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        if(a > b) swap(a, b);
        par[b] = a;
        cnt[a] += cnt[b];
        cnt[b] = 0;
        group--;
    }
}UF;

int N, M;
vector<pii> edge;
vector<int> links[100];

void solve(){
    cin >> N >> M;
    UF.init(N);
    rep(i, 0, M){
        int a, b; cin >> a >> b;
        a--; b--;
        edge.push_back({a, b});
        UF.merge(a, b);
        links[a].push_back(b);
        links[b].push_back(a);
    }
    cout << UF.group << '\n';
    vector<int> ans;
    rep(i, 0, N){
        if(UF.find(i) != i) continue;
        int curmx = 1e9, curidx = -1;
        rep(j, 0, N){
            if(UF.find(j) != i) continue;
            int DP[100];
            fill(DP, DP+100, -1);
            DP[j] = 0;
            queue<int> q;
            q.push(j);
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                for(auto nxt : links[cur]){
                    if(DP[nxt] != -1) continue;
                    DP[nxt] = DP[cur] + 1;
                    q.push(nxt);
                }
            }
            int mx = 0;
            rep(k, 0, N) mx = max(mx, DP[k]);
            if(mx < curmx){
                curmx = mx;
                curidx = j;
            }
        }
        ans.push_back(curidx);
    }
    sort(ans.begin(), ans.end());
    for(auto i: ans) cout << i+1 << '\n';
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