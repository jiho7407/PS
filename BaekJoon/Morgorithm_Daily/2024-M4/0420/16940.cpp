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

int N;
vector<int> links[100001];
int order[100001];
queue<int> q;

void solve(){
    cin >> N;
    rep(i, 0, N-1){
        int a, b;
        cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    rep(i, 1, N+1) cin >> order[i];
    if(order[1] != 1){
        cout << 0;
        return;
    }
    q.push(1);
    int idx = 2, cnt = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        sort(links[cur].begin(), links[cur].end());
        while(idx <= N){
            if(*lower_bound(links[cur].begin(), links[cur].end(), order[idx]) != order[idx]) break;
            q.push(order[idx]);
            idx++;
            cnt++;
        }
    }
    if(cnt == N-1) cout << 1;
    else cout << 0;
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