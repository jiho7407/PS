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

const int mxN = 100000;
int N, M, K;
vector<int> links[mxN];
vector<pii> pairs;
vector<int> cuts;
bool unused[mxN*2];
int group[mxN];

void make_graph(int mid){
    rep(i, 0, N) links[i].clear();
    fill(unused, unused+M, false);
    rep(i, 0, mid) unused[cuts[i]] = true;
    rep(i, 0, M){
        if(unused[i]) continue;
        auto [a, b] = pairs[i];
        links[a].push_back(b);
        links[b].push_back(a);
    }
}

bool check_bin_graph(){
    // 이분그래프인지 확인
    // 0: 미방문, 1: 그룹1, 2: 그룹2
    fill(group, group+N, 0);
    queue<int> q;
    group[0] = 1;
    q.push(0);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto nxt : links[cur]){
            if(group[nxt] == 0){
                group[nxt] = 3 - group[cur];
                q.push(nxt);
            }
            else if(group[nxt] == group[cur]) return false;
        }
    }
    return true;
}

void solve(){
    cin >> N >> M >> K;
    rep(i, 0, M){
        int a, b; cin >> a >> b;
        a--; b--;
        pairs.push_back({a, b});
    }
    rep(i, 0, K){
        int a; cin >> a; a--;
        cuts.push_back(a);
    }

    // 다 잘라서 되는지 안되는지 확인
    make_graph(K);
    if(!check_bin_graph()){ cout << -1 << '\n'; return; }

    // 파라메트릭 서치
    int ok = K, ng = -1;
    while(ok - ng > 1){
        int mid = (ok+ng)>>1;
        make_graph(mid);
        if(check_bin_graph()) ok = mid;
        else ng = mid;
    }
    make_graph(ok);
    check_bin_graph();

    int cnt = 0;
    rep(i, 0, N) if(group[i] == 1) cnt++;
    cout << ok << '\n';
    cout << min(cnt, N-cnt) << ' ' << max(cnt, N-cnt) << '\n';
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