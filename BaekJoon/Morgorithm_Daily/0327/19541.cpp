#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M, K;
vector<int> meet[100010];
bool result[100010], simul[100010], ans[100010];

int main(){
    fastio();
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        cin >> K;
        for(int j = 0; j<K; j++){
            int human;
            cin >> human;
            meet[i].push_back(human-1);
        }
    }
    for(int i = 0; i<N; i++){
        cin >> result[i];
    }
    
    for(int i = 0; i<N; i++) simul[i] = result[i];
    for(int i = M-1; i>=0; i--){
        bool inf = true;
        for(auto h: meet[i]){
            if(simul[h] == 0){
                inf = false;
                break;
            }
        }
        if(!inf){
            for(auto h: meet[i]) simul[h] = false;
        }
    }

    copy(simul, simul+N, ans);
    for(int i = 0; i<M; i++){
        bool inf = false;
        for(auto h: meet[i]){
            if(simul[h]){
                inf = true;
                break;
            }
        }
        if(inf){
            for(auto h: meet[i]) simul[h] = true;
        }
    }
    bool pos = true;
    for(int i = 0; i<N; i++){
        if(simul[i] != result[i]){
            pos = false;
            break;
        }
    }

    if(pos){
        cout << "YES\n";
        for(int i = 0; i<N; i++) cout << ans[i] << " ";
    }
    else cout << "NO";
    
    
    return 0;
}