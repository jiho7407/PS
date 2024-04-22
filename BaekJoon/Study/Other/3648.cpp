#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx = 1010;
int N, M;
vector<int> links[mx*2];
int SCC[2*mx], visited[2*mx];
bool fin[2*mx];
stack<int> stk;
int idx, cnt;

int notP(int a){
    if(a%2) return a-1;
    else return a+1;
}

int sccDfs(int cur){
    visited[cur] = ++idx;
    stk.push(cur);

    int result = visited[cur];
    for(int goal: links[cur]){
        if(visited[goal] == 0) result = min(result, sccDfs(goal));
        else if(!fin[goal]) result = min(result, visited[goal]);
    }

    if(result == visited[cur]){
        cnt++;
        while(true){
            int top = stk.top(); stk.pop();
            SCC[top] = cnt;
            fin[top] = true;
            if(top == cur) break;
        }
    }

    return result;
}

int main(){
    fastio();
    while(cin >> N >> M){
        if(N+M == 0) break;
        for(int i = 0; i<2*N; i++){
            links[i].clear();
        }
        while(M--){
            int a, b;
            cin >> a >> b;
            if(a>0) a = 2*a - 2;
            else a = -2*a - 1;
            if(b>0) b = 2*b - 2;
            else b = -2*b - 1;

            links[notP(a)].push_back(b);
            links[notP(b)].push_back(a);
        }
        links[notP(0)].push_back(0);

        fill(SCC, SCC+2*N, 0);
        fill(visited, visited+2*N, 0);
        fill(fin, fin+2*N, 0);
        idx = cnt = 0;

        for(int i = 0; i<2*N; i++){
            if(visited[i] == 0) sccDfs(i);
        }

        bool pos = true;
        for(int i = 0; i<N; i++){
            if(SCC[2*i] == SCC[2*i+1]) pos = false;
        }

        if(pos) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}