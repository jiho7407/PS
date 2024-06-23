#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const int mx = 5000;
int K, N;
vector<int> links[mx*2]; // 2*i : Red, 2*k+1 : Blue

int notP(int x){
    if(x%2) return x-1;
    return x+1; 
}

int idx = 0, sccidx = 0;
int SCC[mx*2], par[mx*2];
bool finished[mx*2];
stack<int> stk;

int dfs(int cur){
    par[cur] = idx++;
    stk.push(cur);

    int ret = par[cur];
    for(auto nxt: links[cur]){
        if(par[nxt] == -1) ret = min(ret, dfs(nxt));
        else if(!finished[nxt]) ret = min(ret, par[nxt]);
    }

    if(ret == par[cur]){
        while(1){
            int t = stk.top(); stk.pop();
            finished[t] = true;
            SCC[t] = sccidx;
            if(t == cur) break;
        }
        sccidx++;
    }

    return ret;
}

void solve(){
    cin >> K >> N;
    rep(i, 0, N){
        int a1, a2, a3; char c1, c2, c3;
        cin >> a1 >> c1 >> a2 >> c2 >> a3 >> c3;
        a1--; a2--; a3--;
        if(c1 == 'R') a1 = 2*a1;
        else a1 = 2*a1+1;
        if(c2 == 'R') a2 = 2*a2;
        else a2 = 2*a2+1;
        if(c3 == 'R') a3 = 2*a3;
        else a3 = 2*a3+1;
        
        // A, B 만족
        links[notP(a1)].push_back(a2);
        links[notP(a2)].push_back(a1);

        // B, C 만족
        links[notP(a2)].push_back(a3);
        links[notP(a3)].push_back(a2);

        // A, C 만족
        links[notP(a1)].push_back(a3);
        links[notP(a3)].push_back(a1);
    }

    fill_n(par, 2*K, -1);
    rep(i, 0, 2*K){
        if(par[i] == -1) dfs(i);
    }
    rep(i, 0, K){
        if(SCC[2*i] == SCC[2*i+1]){
            cout << "-1\n";
            return;
        }
    }

    rep(i, 0, K){
        if(SCC[2*i] > SCC[2*i+1]) cout << "B";
        else cout << "R";
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