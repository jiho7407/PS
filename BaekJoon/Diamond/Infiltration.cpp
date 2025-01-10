#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

int N;
bitset<75> board[75], ret, cur;
vector<int> ans, tmp;

void btr(int idx){
    if(cur == ret){
        if(ans.empty() || tmp.size() < ans.size()) ans = tmp;
        return;
    }
    if(idx == N) return;
    if(tmp.size() >= ans.size()) return;

    // 사용안함
    btr(idx+1);

    // 사용함
    tmp.push_back(idx);
    bitset<75> save = cur;
    cur |= board[idx];
    if(cur != save) btr(idx+1);
    cur = save;
    tmp.pop_back();
}

void solve(){
    int tc = 1;
    while(cin >> N){
        ret.reset();
        rep(i, 0, N) ret[i].flip();
        rep(i, 0, N){
            string s; cin >> s;
            board[i].reset();
            rep(j, 0, N){
                board[i][j] = s[j] == '1';
            }
            board[i][i] = 1;
        }
        cur.reset();
        ans.resize(6);
        btr(0);

        cout << "Case " << tc++ << ": ";
        cout << ans.size() << ' ';
        for(auto i : ans) cout << i+1 << ' ';
        cout << '\n';
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