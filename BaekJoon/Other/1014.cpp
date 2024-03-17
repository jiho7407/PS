#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 85, mx = 3300;
char board[mxN][mxN];
int numboard[mxN][mxN];
int TC, N, M;
int AM[mx], BM[mx];
bool Avisit[mx];
vector<int> links[mx];
int dx[6] = {-1, 0, 1, -1, 0, 1}, dy[6] = {-1, -1, -1, 1, 1, 1};

bool dfs(int a){
    if(Avisit[a]) return false;
    Avisit[a] = true;

    for(auto b: links[a]){
        if(BM[b] == -1 || dfs(BM[b])){
            AM[a] = b;
            BM[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    fastio();
    cin >> TC;
    while(TC--){
        cin >> N >> M;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cin >> board[i][j];
            }
        }
        int aidx = 0, bidx = 0;
        int all = 0;
        for(int j = 1; j<M; j += 2){
            for(int i = 0; i<N; i++){
                if(board[i][j] == 'x') continue;
                numboard[i][j] = ++bidx;
                all++;
            }
        }
        for(int j = 0; j<M; j += 2){
            for(int i = 0; i<N; i++){
                if(board[i][j] == 'x') continue;
                aidx++;
                all++;
                links[aidx].clear();
                for(int d = 0; d<6; d++){
                    int px, py;
                    px = i + dx[d];
                    py = j + dy[d];
                    if(px<0 || px>=N || py<0 || py>=M) continue;
                    if(board[px][py] == 'x') continue;
                    links[aidx].push_back(numboard[px][py]);
                }
            }
        }
        int match = 0;
        fill(AM, AM+mx, -1);
        fill(BM, BM+mx, -1);
        for(int i = 1; i<=aidx; i++){
            fill(Avisit, Avisit+aidx+1, false);
            if(dfs(i)) match++;
        }

        cout << all - match << "\n";
    }
    return 0;
}