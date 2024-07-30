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
int inlinks[100000];
int nxt[100000];
bool visited[100000];
vector<int> ans;

void solve(){
    cin >> N;
    rep(i, 0, N){
        int x; cin >> x; x--;
        nxt[i] = x;
        inlinks[x]++;
    }
    inlinks[0] = 0;
    rep(i, 0, N){
        if(visited[i]) continue;
        if(inlinks[i] != 0) continue;
        int cur = i;
        ans.push_back(cur);
        while(!visited[cur]){
            visited[cur] = true;
            cur = nxt[cur];
            ans.push_back(cur);
        }
    }
    rep(i, 0, N){
        if(visited[i]) continue;
        int cur = i;
        ans.push_back(cur);
        while(!visited[cur]){
            visited[cur] = true;
            cur = nxt[cur];
            ans.push_back(cur);
        }
    }
    if(ans[0] == 0) ans.erase(ans.begin());
    cout << ans.size() << '\n';
    for(auto x: ans){
        cout << x+1 << ' ';
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