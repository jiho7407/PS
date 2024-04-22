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

int N, M;
int root[50000], inlink[50000];
vector<pii> tempquery;
vector<int> links[50000];
int linkcnt = 0;

int find(int x){
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(x > y) swap(x, y);
    root[y] = x;
    return;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, N) root[i] = i;
    rep(i, 0, M){
        int a, c; char b;
        cin >> a >> b >> c;
        if(b == '='){merge(a, c); continue;}
        tempquery.push_back({a, c});
    }
    for(auto query : tempquery){
        int a = find(query.first);
        int b = find(query.second);
        if(a == b){
            cout << "inconsistent";
            return;
        }
        links[a].push_back(b);
        inlink[b]++;
        linkcnt++;
    }
    queue<int> q;
    rep(i, 0, N) if(inlink[i] == 0) q.push(i);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto next : links[cur]){
            inlink[next]--;
            linkcnt--;
            if(inlink[next] == 0) q.push(next);
        }
    }
    if(linkcnt == 0) cout << "consistent";
    else cout << "inconsistent";
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