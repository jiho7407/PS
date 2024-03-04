#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx=100010;
int N;
vector<pair<int, int>> links[mx];
int ant[mx];
int tree[20][mx];
int cost[20][mx];

void maketree(int cur, int par){
    for(auto pair: links[cur]){
        int goal = pair.first, weight = pair.second;
        if(goal==par) continue;
        tree[0][goal] = cur;
        cost[0][goal] = weight;
        maketree(goal, cur);
    }
}

int solve(int a){
    int eng = ant[a];
    int cur = a;
    for(int i = 19; i>=0; i--){
        if(tree[i][cur] == 0) continue;
        if(cost[i][cur] > eng) continue;
        eng -= cost[i][cur];
        cur = tree[i][cur];
    }
    return cur;
}

int main(){
    fastio();
    cin >> N;
    for(int i = 0; i<20; i++) fill(tree[i], tree[i]+N, 0);
    for(int i = 1; i<=N; i++){
        int eng;
        cin >> eng;
        ant[i] = eng;
    }
    for(int i = 0; i<N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        links[a].push_back({b, c});
        links[b].push_back({a, c});
    }
    maketree(1, 0);
    for(int i = 1; i<20; i++){
        for(int j = 1; j<=N; j++){
            tree[i][j] = tree[i-1][tree[i-1][j]];
            cost[i][j] = cost[i-1][j] + cost[i-1][tree[i-1][j]];
            if(cost[i][j]>mx) cost[i][j] = mx;
        }
    }
    for(int i = 1; i<=N; i++) cout << solve(i) << "\n";
    // for(int i = 0; i<5; i++){
    //     for(int j = 1; j<=N; j++){
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}