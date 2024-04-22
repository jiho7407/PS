#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx = 510;
int N, K;
int AM[mx], BM[mx];
vector<int> links[mx];
bool Avisit[mx];

bool dfs(int a){
    if(Avisit[a]) return false;
    Avisit[a] = true;

    for(auto b: links[a]){
        if(BM[b]==-1 || dfs(BM[b])){
            AM[a] = b;
            BM[b] = a;
            return true;
        }
    }
    return false;
}

int main(){
    fastio();
    cin >> N >> K;
    int a, b;
    while(K--){
        cin >> a >> b;
        links[a-1].push_back(b-1);
    }
    int match = 0;
    fill(AM, AM+N, -1);
    fill(BM, BM+N, -1);
    for(int i = 0; i<N; i++){
        fill(Avisit, Avisit+N, false);
        if(dfs(i)) match++;
    }
    cout << match;
    return 0;
}