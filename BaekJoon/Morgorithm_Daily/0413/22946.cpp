#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
tuple<int, ll, ll , ll> circles[5010];
vector<int> links[5010];
int depth[5010];

bool cmp(tuple<int, ll, ll, ll> a, tuple<int, ll, ll, ll> b){
    return get<3>(a) > get<3>(b);
}

bool AinB(tuple<int, ll, ll, ll> a, tuple<int, ll, ll, ll> b){
    ll x1 = get<1>(a), y1 = get<2>(a), r1 = get<3>(a);
    ll x2 = get<1>(b), y2 = get<2>(b), r2 = get<3>(b);
    ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return dist < (r1-r2)*(r1-r2);
}

void dfs(int cur, int par, int idx){
    bool find = false;
    for(auto goal: links[cur]){
        if (goal == par) continue;
        if(AinB(circles[idx], circles[goal])){
            dfs(goal, cur, idx);
            find = true;
        }
    }
    if(!find){
        links[cur].push_back(idx);
        links[idx].push_back(cur);
    }
}

void dfs2(int cur, int par, int lev){
    depth[cur] = lev;
    for(auto next: links[cur]){
        if(next == par) continue;
        dfs2(next, cur, lev+1);
    }
    return;
}

int getmxidx(int array[], int size){
    int mx = -1, idx = -1;
    for(int i = 0; i < size; i++){
        if(array[i] > mx){
            mx = array[i];
            idx = i;
        }
    }
    return idx;
}

void solve(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        int x, y, r;
        cin >> x >> y >> r;
        circles[i] = {i, x, y, r};
    }
    sort(circles+1, circles+N+1, cmp);
    for(int i = 1; i <= N; i++) dfs(0, -1, i);
    fill(depth, depth+N+1, 0);
    dfs2(0, -1, 0);
    int mx = getmxidx(depth, N+1);
    fill(depth, depth+N+1, 0);
    dfs2(mx, -1, 0);
    cout << depth[getmxidx(depth, N+1)] << "\n";
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