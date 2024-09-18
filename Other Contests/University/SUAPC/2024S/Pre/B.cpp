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
vector<char> ans[600];
random_device rd;
mt19937 g(rd());


void solve(){
    cin >> N;
    rep(i, 0, N){
        ans[i].push_back('R');
        ans[i].push_back('S');
        ans[i].push_back('P');
        shuffle(ans[i].begin(), ans[i].end(), g);
        for(auto &c : ans[i]) cout << c;
        cout << '\n';
    }
    while(1){
        cout << "? ";
        rep(i, 0, N) cout << ans[i][0];
        cout << '\n';
        cout.flush();

        int a, b, c; cin >> a >> b >> c;
        if(b == -1 && c == -1) break;

        b--; c--;
        int mn = 1e9;
        if(b != -1) mn = min(mn, b);
        if(c != -1) mn = min(mn, c);

        rep(i, 0, mn-1){
            int sz = ans[i].size();
            cout << "sz : " << sz << endl;
            rep(j, 0, sz-1) ans[i].pop_back();
        }

        if(b == c) ans[b].erase(ans[b].begin());
        else{
            if(b != -1) ans[b].erase(ans[b].begin());
            if(c != -1) ans[c].erase(ans[c].begin());
        }
    }
    cout << "! ";
    rep(i, 0, N) cout << ans[i][0];
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