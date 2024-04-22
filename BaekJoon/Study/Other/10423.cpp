#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int MX = 1010;
int N, M, K;
vector<tuple<int, int, int>> links;
int pa[MX];
bool elec[MX];

bool cmp(tuple<int, int, int> a, tuple<int, int, int> b){
    return get<2>(a) < get<2>(b);
}

int findroot(int a){
    if(a == pa[a]) return a;
    pa[a] = findroot(pa[a]);
    return pa[a];
}

bool merge(int a, int b){
    int aroot, broot;
    aroot = findroot(a);
    broot = findroot(b);
    if(aroot == broot) return false;
    if(elec[aroot] && elec[broot]) return false;

    if(elec[aroot]) elec[broot] = true;
    else if(elec[broot]) elec[aroot] = true;

    if(aroot < broot) pa[broot] = aroot;
    else pa[aroot] = broot;
    return true;
}

int main(){
    fastio();
    cin >> N >> M >> K;
    fill(elec, elec+N+1, false);
    for(int i = 0; i<K; i++){
        int e;
        cin >> e;
        elec[e] = true;
    }

    int u, v, w;
    while(M--){
        cin >> u >> v >> w;
        links.push_back({u, v, w});
    }
    sort(links.begin(), links.end(), cmp);
    for(int i = 1; i<=N; i++) pa[i] = i;

    int ans = 0;
    int con = 0;
    for(auto c: links){
        tie(u, v, w) = c;
        if(merge(u, v)){
            con++;
            ans += w;
        }
        if(con == N-K) break;
    }
    cout << ans;
    return 0;
}