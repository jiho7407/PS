#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx = 1010;
int TC, N, M;
vector<int> links[mx];
int AM[mx], BM[mx];
bool Avisit[mx];

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
        for(int i=0; i<M; i++) links[i].clear();
        int a, b;
        for(int i = 0; i<M; i++){
            cin >> a >> b;
            for(int j = a; j<=b; j++){
                links[i].push_back(j-1);
            }
        }
        int match = 0;
        fill(AM, AM+M, -1);
        fill(BM, BM+N, -1);
        for(int i = 0; i<M; i++){
            fill(Avisit, Avisit+M, false);
            if(dfs(i)) match++;
        }
        cout << match << "\n";
    }
    return 0;
}