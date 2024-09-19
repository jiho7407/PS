#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000010;

int N,M,sz;
vector<int> g[MAX];
map<string,int> mp[MAX];
int leafs[MAX];
int ans;

void dfs(int cur, int cnt){
    for(auto goal: g[cur]){
        ans = min(ans, cnt+M-2*leafs[goal]);
        dfs(goal, cnt+M-2*leafs[goal]);
    }
}

void solve(){
    cin >> M;
    N = 1;
    int u = 0;
    ans = 0;
    fill(leafs, leafs+MAX, 0);
    for (int j=0;j<M;j++){
        u = 0;
        string s; cin>>s;
        s.push_back('/');
        string t = "";
        for (int i=1;i<s.length();i++){
            if (s[i]=='/'){
                ans++;
                leafs[u]++;
                if (mp[u].find(t)==mp[u].end()){
                    ++N;
                    mp[u][t] = N-1;
                    g[u].push_back(mp[u][t]);
                }
                u = mp[u][t];
                t = "";
            }else{
                t.push_back(s[i]);
            }
        }
    }
    dfs(0, ans);
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}