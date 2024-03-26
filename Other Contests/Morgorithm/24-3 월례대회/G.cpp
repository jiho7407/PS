#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M, K;
int visited[3010][3010];
vector<tuple<int, int, int>> lst;
queue<tuple<int, int, int>> Q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    fastio();
    cin >> N >> M >> K;
    for(int i = 0; i<N; i++) fill(visited[i], visited[i]+M, 0);
    for (int i = 0; i < K; ++i) {
        int x, y, p;
        cin >> x >> y >> p;
        lst.push_back({x-1, y-1, p});
    }

    sort(lst.begin(), lst.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<2>(a) > get<2>(b);
    });

    int ans = 0;
    for(const auto& [x, y, p]: lst){
        cout << p << " ";
        if(visited[x][y] >= p) continue;
        if(visited[x][y] == 0) ans++;
        visited[x][y] = p + 1;
        Q.push({x, y, p});
        while(!Q.empty()){
            auto [cx, cy, move] = Q.front(); Q.pop();
            for(int d = 0; d < 4; ++d){
                int px = cx + dx[d];
                int py = cy + dy[d];
                if(px < 0 || px >= N || py < 0 || py >= M) continue;
                if(visited[px][py] >= move) continue;
                if(visited[px][py] == 0) ans++;
                visited[px][py] = move;
                Q.push({px, py, move - 1});
            }
        }
    }

    // for(int i = 0; i<N; i++){
    //     for(int j = 0; j<M; j++) cout << visited[i][j] << " ";
    //     cout << "\n";
    // }

    cout << ans;
    return 0;
}
