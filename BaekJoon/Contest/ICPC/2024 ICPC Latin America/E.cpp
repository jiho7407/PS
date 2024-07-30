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

pii se[1001];
vector<int> links[1001];
int group[1001];
bool visited[1001];

void solve(){
    int N; cin >> N;
    rep(i, 0, 2*N){
        int a; cin >> a;
        if(a > 0) se[a].first = i;
        else se[-a].second = i;
    }
    rep(i, 1, N+1) rep(j, i+1, N+1){
        auto [a, b] = se[i];
        auto [c, d] = se[j];
        if(a > c) swap(a, c), swap(b, d);
        if(a < c and c < b and b < d){
            links[i].push_back(j);
            links[j].push_back(i);
        }
    }
    fill(group, group+N+1, -1);
    rep(i, 1, N+1){
        if(group[i] == -1){
            group[i] = 0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nxt: links[cur]){
                    if(group[nxt] == -1){
                        group[nxt] = group[cur] ^ 1;
                        q.push(nxt);
                    }
                    else{
                        if(group[nxt] == group[cur]){
                            cout << "*";
                            return;
                        }
                    }
                }
            }
        }
    }
    rep(i, 1, N+1) cout << (group[i] ? 'S' : 'G');
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