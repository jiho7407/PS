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

const int mxN = 10000;
int N;
int A[mxN], B[mxN], level[mxN];
bool used[mxN];
vector<int> links[mxN];

void bfs(){
    queue<int> Q;
    rep(i, 0, N){
        if(!used[i]){
            level[i] = 0;
            Q.push(i);
        }
        else level[i] = -1;
    }

    while(!Q.empty()){
        int a = Q.front(); Q.pop();
        for(auto b: links[a]){
            if(B[b] != -1 && level[B[b]] == -1){
                level[B[b]] = level[a] + 1;
                Q.push(B[b]);
            }
        }
    }
}

bool dfs(int a){
    for(int b: links[a]){
        if(B[b] == -1 || (level[B[b]] == level[a] + 1 && dfs(B[b]))){
            used[a] = true;
            A[a] = b;
            B[b] = a;
            return true;
        }
    }
    return false;
}


void solve(){
    while(scanf("%d", &N) != EOF){
        rep(i, 0, N){
            int a, cnt;
            scanf("%d: (%d)", &a, &cnt);
            rep(j, 0, cnt){
                int b;
                scanf("%d", &b);
                links[a].push_back(b-N);
            }
        }
        int match = 0;
        fill(A, A+N, -1);
        fill(B, B+N, -1);
        fill(used, used+N, false);
        while(1){
            bfs();
            int flow = 0;
            rep(i, 0, N) if(!used[i] && dfs(i)) flow++;
            if(flow == 0) break;
            match += flow;
        }
        cout << match << "\n";

        rep(i, 0, N) links[i].clear();
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