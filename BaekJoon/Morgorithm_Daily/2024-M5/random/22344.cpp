#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<ll, ll> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N, M, x;
vector<pii> links[100000];
bool visited[100000], decide;
pii nodes[100000];

void dfs(ll cur, ll par){
    for(auto [nxt, cost] : links[cur]){
        if(nxt == par) continue;
        if(visited[nxt]){
            pii tmp = {nodes[cur].first+nodes[nxt].first, nodes[cur].second+nodes[nxt].second};
            if(tmp.first == 0){
                if(tmp.second == cost) continue;
                else{
                    cout << "NO";
                    exit(0);
                }
            }
            else{
                if(decide){
                    if(tmp.first*x + tmp.second == cost) continue;
                    else{
                        cout << "NO";
                        exit(0);
                    }
                }
                else{
                    if((cost-tmp.second)%(tmp.first) == 0){
                        x = (cost-tmp.second)/(tmp.first);
                        decide = true;
                    }
                    else{
                        cout << "NO";
                        exit(0);
                    }
                }
            }
        }
        else{
            visited[nxt] = true;
            nodes[nxt] = {-nodes[cur].first, cost-nodes[cur].second};
            dfs(nxt, cur);
        }
    }
    return;
}

void solve(){
    cin >> N >> M;
    rep(i, 0, M){
        ll s, e, c; cin >> s >> e >> c; s--; e--;
        links[s].push_back({e, c});
        links[e].push_back({s, c});
    }
    nodes[0] = {1, 0};
    visited[0] = true;
    decide = false;
    dfs(0, -1);
    cout << "YES\n";
    if(!decide){
        vector<ll> v;
        rep(i, 0, N){
            v.push_back(-nodes[i].second/nodes[i].first);
        }
        sort(v.begin(), v.end());
        x = v[N/2];
    }
    rep(i, 0, N){
        cout << nodes[i].first*x + nodes[i].second << ' ';
    }
    // rep(i, 0, N){
    //     cout << nodes[i].first << ' ' << nodes[i].second << '\n';
    // }
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