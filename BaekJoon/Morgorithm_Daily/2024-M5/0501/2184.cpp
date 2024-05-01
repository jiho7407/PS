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

const ll INF = 1e18;
int N, L;
vector<int> X;
ll DP[1001][1001][2];

void dfs(int start, int end, bool isright){
    ll rest = N - (end - start + 1);

    // 왼쪽으로
    if(start > 0){
        int next = start - 1;
        if(isright){
            ll dist = X[end] - X[next];
            ll cost = dist*rest;
            if (DP[next][end][0] > DP[start][end][1] + cost){
                DP[next][end][0] = DP[start][end][1] + cost;
                dfs(next, end, 0);
            }
        }else{
            ll dist = X[start] - X[next];
            ll cost = dist*rest;
            if (DP[next][end][0] > DP[start][end][0] + cost){
                DP[next][end][0] = DP[start][end][0] + cost;
                dfs(next, end, 0);
            }
        }
    }
    // 오른쪽으로
    if(end < N){
        int next = end + 1;
        if(isright){
            ll dist = X[next] - X[end];
            ll cost = dist*rest;
            if(DP[start][next][1] > DP[start][end][1] + cost){
                DP[start][next][1] = DP[start][end][1] + cost;
                dfs(start, next, 1);
            }
        }else{
            ll dist = X[next] - X[start];
            ll cost = dist*rest;
            if(DP[start][next][1] > DP[start][end][0] + cost){
                DP[start][next][1] = DP[start][end][0] + cost;
                dfs(start, next, 1);
            }
        }
    }
}

void solve(){
    cin >> N >> L;
    X.push_back(L);
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        X.push_back(x);
    }
    N++;
    sort(X.begin(), X.end());
    ll start = lower_bound(X.begin(), X.end(), L) - X.begin();
    rep(i, 0, N)rep(j, 0, N) DP[i][j][0] = DP[i][j][1] = INF;
    DP[start][start][0] = DP[start][start][1] = 0;
    dfs(start, start, 0);
    cout << min(DP[0][N-1][0], DP[0][N-1][1]);
    // rep(i, 0, N){
    //     rep(j, 0, N) cout << DP[i][j][0] << " ";
    //     cout << "\n";
    // }
    // rep(i, 0, N){
    //     rep(j, 0, N) cout << DP[i][j][1] << " ";
    //     cout << "\n";
    // }
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