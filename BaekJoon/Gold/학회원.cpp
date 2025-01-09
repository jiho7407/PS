#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

vector<string> split(const string S, char c){
    vector<string> ret;
    string temp = "";
    for(auto s : S){
        if(s == c){
            ret.push_back(temp);
            temp = "";
        }
        else temp += s;
    }
    ret.push_back(temp);
    return ret;
}

int N;
map<string, int> mp;
vector<vector<string>> V;
vector<vector<int>> links;
vector<bool> visited;

int dfs(int idx){
    if(visited[idx]) return 0;
    visited[idx] = true;
    if(idx >= N) return 1;
    int ret = 0;
    for(auto nxt : links[idx]){
        ret += dfs(nxt);
    }
    return ret;
}

void solve(){
    while(1){
        cin >> N;
        if(N == 0) return;
        int idx = 0;
        rep(i, 0, N){
            string S; cin >> S;
            S = S.substr(0, S.size()-1);
            vector<string> tmp = split(S, ':');
            mp[tmp[0]] = idx++;
            V.push_back(split(tmp[1], ','));
        }
        rep(i, 0, N){
            vector<int> tmp;
            for(auto s: V[i]){
                int nxt;
                if(mp.find(s) == mp.end()) mp[s] = idx++;
                tmp.push_back(mp[s]);
            }
            links.push_back(tmp);
        }
        visited.resize(idx);
        rep(i, 0, idx) visited[i] = false;
        cout << dfs(0) << '\n';

        mp.clear();
        V.clear();
        links.clear();
        visited.clear();
    }
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}