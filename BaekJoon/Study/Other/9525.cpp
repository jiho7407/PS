#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mxN = 105;
int N;
string board[mxN];

const int mx = 10010;
int AM[mx], BM[mx];
vector<int> Alink[mx];
bool Avisit[mx];

int hrz[mxN][mxN];

bool dfs(int a){
    if(Avisit[a]) return false;
    Avisit[a] = true;

    for(auto b : Alink[a]){
        if(!BM[b] || dfs(BM[b])){
            AM[a] = b;
            BM[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    fastio();
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> board[i];
    }

    int hnum = 0;
    for(int i = 0; i<N; i++){
        fill(hrz[i], hrz[i]+N, 0);
        hnum++;
        for(int j = 0; j<N; j++){
            if(board[i][j] == '.') hrz[i][j] = hnum;
            else hnum++;
        }
    }

    int vnum = 0;
    for(int i = 0; i<N; i++){
        vnum++;
        for(int j = 0; j<N; j++){
            if(board[j][i] == '.') Alink[vnum].push_back(hrz[j][i]);
            else vnum++;
        }
    }

    int match = 0;
    for(int i = 1; i<=vnum; i++){
        if(Alink[i].empty()) continue;
        fill(Avisit, Avisit+vnum+1, false);
        if(dfs(i)) match++;
        // for(int i = 1; i<=vnum; i++) cout << AM[i] << " ";
        // cout << "\n";
        // for(int i = 1; i<=hnum; i++) cout << BM[i] << " ";
        // cout << "\n";
    }
    cout << match;

}