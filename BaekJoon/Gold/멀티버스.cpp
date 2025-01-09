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

void solve(){
    int M, N; cin >> M >> N;
    vector<vector<int>> univ;
    rep(i, 0, M){
        vector<int> v1, v2;
        rep(j, 0, N){
            int sz; cin >> sz;
            v1.push_back(sz);
            v2.push_back(sz);
        }
        sort(v2.begin(), v2.end());
        v2.erase(unique(v2.begin(), v2.end()), v2.end());
        rep(j, 0, N){
            v1[j] = lower_bound(v2.begin(), v2.end(), v1[j]) - v2.begin();
        }
        univ.push_back(v1);
    }

    int cnt = 0;
    rep(i, 0, M) rep(j, i+1, M){
        bool flag = true;
        rep(k, 0, N) if(univ[i][k] != univ[j][k]){
            flag = false;
            break;
        }
        if(flag) cnt++;
    }

    cout << cnt;
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