#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
bool friends[50][50];

void solve(){
    cin >> N >> M;
    fill_n(&friends[0][0], 50*50, false);
    rep(i, 0, M){
        int a, b; cin >> a >> b; a--; b--;
        friends[a][b] = friends[b][a] = true;
    }
    rep(i, 0, N) friends[i][i] = true;
    vector<int> ans;
    while(1){
        bool flag = true;
        rep(i, 0, N) rep(j, i+1, N) if(!friends[i][j]) flag = false;
        if(flag) break;
        int cnt = 0;
        bool temp[50][50];
        fill_n(&temp[0][0], 50*50, false);
        rep(i, 0, N) rep(j, 0, N){
            if(friends[i][j]) temp[i][j] = true;
            else{
                rep(k, 0, N){
                    if(friends[i][k] && friends[j][k]){
                        temp[i][j] = temp[j][i] = true;
                        cnt++;
                        break;
                    }
                }
            }
        }
        rep(i, 0, N) rep(j, 0, N) friends[i][j] = temp[i][j];
        ans.push_back(cnt/2);
    }
    cout << ans.size() << '\n';
    for(auto x: ans){
        cout << x << "\n";
    }
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}