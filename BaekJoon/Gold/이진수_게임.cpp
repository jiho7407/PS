/*###################################################
##           Author: Jiho Kim (wlgh7407)           ##
###################################################*/

// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("bmi2","adx","avx2")
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define rrep(i, r, l) for(int i = r-1; i >= l; i--)
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

string to_bin(int n){
    string ret;
    while(n){
        if(n%2) ret += '1';
        else ret += '0';
        n /= 2;
    }
    reverse(all(ret));
    return ret;
}

int to_int(string s){
    int ret = 0;
    for(char c : s){
        ret *= 2;
        ret += c - '0';
    }
    return ret;
}

void solve(){
    string S, T; cin >> S >> T;
    int N = to_int(S), M = to_int(T);
    queue<pii> q;
    vector<bool> visited(1024, false);
    visited[N] = true;
    q.push({N, 0});
    while(!q.empty()){
        auto [cur, cnt] = q.front(); q.pop();
        if(cur == M){
            cout << cnt << '\n';
            return;
        }
        // op 1
        rep(i, 0, 10){
            if(cur/2 < (1 << i)) break;
            int nxt = cur ^ (1 << i);
            if(!visited[nxt]){
                visited[nxt] = true;
                q.push({nxt, cnt + 1});
            }
        }

        // op 2, 3
        if(cur+1 < 1024 && !visited[cur + 1]){
            visited[cur + 1] = true;
            q.push({cur + 1, cnt + 1});
        }
        if(cur-1 >= 0 && !visited[cur - 1]){
            visited[cur - 1] = true;
            q.push({cur - 1, cnt + 1});
        }
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