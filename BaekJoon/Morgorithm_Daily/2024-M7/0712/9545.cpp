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

int N;
bool ok[26][26];
int mxsz;
vector<int> cycle, mxcycle;

void dfs(){
    if(cycle.size() > mxsz){
        mxsz = cycle.size();
        mxcycle = cycle;
    }
    if(mxsz >= 39) return;
    rep(i, 0, 26){
        if(!cycle.empty() && !ok[cycle.back()][i]) continue;
        cycle.push_back(i);
        dfs();
        cycle.pop_back(); 
    }
}

void solve(){
    cin >> N;
    fill_n(&ok[0][0], 26*26, true);
    rep(i, 0, N){
        string S; cin >> S;
        ok[S[0]-'a'][S[1]-'a'] = false;
    }
    dfs();
    rep(i, 0, (mxsz+1)/2){
        rep(j, 0, (mxsz+1)/2) cout << (char)(mxcycle[i+j]+'a');
        cout << '\n';
    }
    mxsz = 0;
    cycle.clear();
    mxcycle.clear();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}