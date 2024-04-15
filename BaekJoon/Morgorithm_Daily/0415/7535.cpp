#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
vector<int> links[2001];
int bug[2001];

void solve(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        links[i].clear();
    }
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        links[a].push_back(b);
        links[b].push_back(a);
    }
    fill(bug, bug + N + 1, -1);
    queue<int> q;
    bool pos = true;
    for(int i = 1; i <= N; i++){
        if(bug[i] != -1) continue;
        q.push(i); bug[i] = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int next : links[cur]){
                if(bug[next] == -1){
                    bug[next] = 1 - bug[cur];
                    q.push(next);
                }
                if (bug[next] == bug[cur]){
                    pos = false;
                    break;
                }
            }
        }
    }
    if(pos) cout << "No suspicious bugs found!\n";
    else cout << "Suspicious bugs found!\n";

    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    for(int i = 1; i <= tc; i++){
        cout << "Scenario #" << i << ":\n";
        solve();
        cout << "\n";
    }
    return 0;
}