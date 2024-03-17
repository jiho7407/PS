#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx = 20100, INF = 2147483647;
int N, M, S, E;
map<pair<int, int>, int> cap, flow;
int work[mx], lev[mx];
vector<int> links[mx];
vector<string> board;
int dx[2] = {1, 0}, dy[2] = {0, 1};

bool bfs(){
    fill(lev, lev+mx, -1);
    lev[S] = 0;

    queue<int> Q; Q.push(S);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(auto goal: links[cur]){
            if(lev[goal] == -1 && cap[{cur, goal}] - flow[{cur, goal}]>0){
                lev[goal] = lev[cur]+1;
                Q.push(goal);
            }
        }
    }
    
    return lev[E] != -1;
}

int dfs(int cur, int f){
    if(cur == E) return f;

    for(int &i = work[cur]; i<links[cur].size(); i++){
        int next = links[cur][i];
        int posf = cap[{cur, next}] - flow[{cur, next}];
        if(lev[next] == lev[cur]+1 && posf>0){
            int tempf = dfs(next, min(f, posf));
            if(tempf > 0){
                flow[{cur, next}] += tempf;
                flow[{next, cur}] -= tempf;
                return tempf;
            }
        }
    }
    return 0;
}

int main(){
    fastio();
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        string cmd;
        cin >> cmd;
        board.push_back(cmd);
    }
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            int head = 2*(M*i+j), tail = head+1;

            if(board[i][j] == '#') continue;

            cap[{head, tail}] = 1;
            links[head].push_back(tail);
            links[tail].push_back(head);
            if(board[i][j] == 'K') S = tail;
            if(board[i][j] == 'H') E = head;

            for(int d = 0; d<2; d++){
                int px, py;
                px = i + dx[d];
                py = j + dy[d];
                if(px < 0 || px >= N || py < 0 || py >= M) continue;
                if(board[px][py] == '#') continue;
                cap[{tail, 2*(M*px+py)}] = 100000;
                cap[{2*(M*px+py)+1, head}] = 100000;
                cap[{2*(M*px+py), tail}] = 0;
                cap[{head, 2*(M*px+py)+1}] = 0;
                links[tail].push_back(2*(M*px+py));
                links[2*(M*px+py)+1].push_back(head);
                links[2*(M*px+py)].push_back(tail);
                links[head].push_back(2*(M*px+py)+1);
            }
        }
    }

    if(cap[{S, E}] > 0){
        cout << -1;
        return 0;
    }

    int MF = 0;
    while(bfs()){
        fill(work, work+mx, 0);
        while(true){
            int f = dfs(S, INF);
            if(f==0) break;
            MF += f;
        }
    }
    cout << MF;
    return 0;
}