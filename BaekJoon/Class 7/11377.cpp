#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx = 1010;
int N, M, K;
int AM[mx*2], BM[mx];
bool Avisit[2*mx];
vector<int> links[2*mx];

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
    cin >> N >> M >> K;
    for(int i = 0; i<N; i++){
        int cnt;
        cin >> cnt;
        for(int j = 0; j<cnt; j++){
            int work;
            cin >> work;
            links[i*2].push_back(work);
            links[i*2+1].push_back(work);
        }
    }


    fill(AM, AM+2*N, -1);
    fill(BM, BM+M+1, -1);

    int ans=0;
    for(int i = 0; i<N; i++){
        fill(Avisit, Avisit+2*N, false);
        if(dfs(i*2)) ans++;
    }

    int kans=0;
    for(int i = 0; i<N; i++){
        fill(Avisit, Avisit+2*N, false);
        if(dfs(i*2+1)) kans++;
        if(kans == K) break;
    }

    cout << ans + kans;
    return 0;
}