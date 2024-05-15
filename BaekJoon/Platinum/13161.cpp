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

const int S = 500, T = 501, INF = 1e9;
int N;
int camp[500];
int w[500][500];
int cap[502][502], flow[502][502];

vector<int> links[502];

void solve(){
    cin >> N;
    rep(i, 0, 502) fill(cap[i], cap[i] + 502, 0);
    rep(i, 0, 502) fill(flow[i], flow[i] + 502, 0);
    rep(i, 0, N) cin >> camp[i];
    rep(i, 0, N) rep(j, 0, N) cin >> w[i][j];
    rep(i, 0, N){
        if(camp[i] == 1) {links[S].push_back(i); c[S][i] = INF;}
        else if(camp[i] == 2) {links[i].push_back(T); c[i][T] = INF;}
        else{
            links[S].push_back(i);
            links[i].push_back(i+N);
            links[i+N].push_back(i);
            links[i+N].push_back(T);
        }
    }
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