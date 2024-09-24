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
int A[2000];
vector<pii> lblock, rblock;

void solve(){ 
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    bool flag = true;
    rep(i, 1, N){
        int cur = A[i-1];
        int nxt = A[i];
        if(i%2){ // 왼쪽에서 꺾임
            for(auto [s, e]: lblock){
                bool c1 = s <= cur && cur <= e;
                bool c2 = s <= nxt && nxt <= e;
                if(c1 ^ c2) flag = false;
            }
            lblock.push_back({min(cur, nxt), max(cur, nxt)});
        }
        else{
            for(auto [s, e]: rblock){
                bool c1 = s <= cur && cur <= e;
                bool c2 = s <= nxt && nxt <= e;
                if(c1 ^ c2) flag = false;
            }
            rblock.push_back({min(cur, nxt), max(cur, nxt)});
        }
    }
    if(flag) cout << "YES\n";
    else cout << "NO\n";

    lblock.clear();
    rblock.clear();
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