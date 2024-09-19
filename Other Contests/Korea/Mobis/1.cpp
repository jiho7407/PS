#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
#define rep(i, l, r) for(int i = l; i<r; i++)
using namespace std;

vector<int> links[3000];
int idx[3000], id = 0;
bool finished[3000];
int SCC[3000], SCCid = 0;
int SCCcnt[3000], outdeg[3000];
stack<int> st;

int dfs(int x){
    idx[x] = ++id;
    st.push(x);

    int parent = idx[x];
    for(auto nx: links[x]){
        if(idx[nx] == 0) parent = min(parent, dfs(nx));
        else if(!finished[nx]) parent = min(parent, idx[nx]);
    }

    if(parent == idx[x]){
        while(1){
            int t = st.top(); st.pop();
            finished[t] = true;
            SCC[t] = SCCid;
            SCCcnt[SCCid]++;
            if(t == x) break;
        }
        SCCid++;
    }

    return parent;
}

int solution(int n, vector<vector<int>> edges){
    for(auto v: edges){
        int a = v[0], b = v[1];
        a--; b--;
        links[a].push_back(b);
    }
    fill(idx, idx+n, 0);
    fill(finished, finished+n, false);
    fill(SCC, SCC+n, -1);
    rep(i, 0, n) if(idx[i] == 0) dfs(i);

    for(auto v: edges){
        int a = v[0], b = v[1];
        a--; b--;
        if(SCC[a] != SCC[b]) outdeg[SCC[a]]++;
    }
    rep(i, 0, SCCid){
        cout << i << ' ' << SCCcnt[i] << ' ' << outdeg[i] << '\n';
    }

    int answer = 0;
    return answer;
}

int main(){
    // int n = 5;
    // vector<vector<int>> edges = {{1, 2}, {3, 2}, {2, 5}, {4, 5}, {5, 1}};

    // int n = 4; vector<vector<int>> edges = {{2, 1}, {3, 4}, {1, 4}, {2, 3}};

    // int n = 4; vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 1}};

    int n = 4; vector<vector<int>> edges = {{1, 2}, {2, 1}, {2, 3}, {3, 4}, {4, 2}};
    cout << solution(n, edges);
}