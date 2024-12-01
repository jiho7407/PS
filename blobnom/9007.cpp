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
    int K, N; cin >> K >> N;
    vector<int> v[4];
    rep(i, 0, 4){
        v[i].resize(N);
        rep(j, 0, N) cin >> v[i][j];
    }

    vector<int> sum[2];
    rep(i, 0, N) rep(j, 0, N){
        sum[0].push_back(v[0][i] + v[1][j]);
        sum[1].push_back(v[2][i] + v[3][j]);
    }

    sort(sum[0].begin(), sum[0].end());
    sort(sum[1].begin(), sum[1].end());

    int ans = sum[0][0] + sum[1][0];
    
    for(auto A: sum[0]){
        int goal = K - A;
        auto it = lower_bound(sum[1].begin(), sum[1].end(), goal);
        if(it == sum[1].end()) it--;
        if(*it == goal){
            ans = K;
            break;
        }
        
        // it와 비교
        if(abs(*it + A - K) < abs(ans - K)) ans = *it + A;
        else if(abs(*it + A - K) == abs(ans - K)) ans = min(ans, *it + A);

        // it-1과 비교
        if(it == sum[1].begin()) continue;
        it--;
        if(abs(*it + A - K) < abs(ans - K)) ans = *it + A;
        else if(abs(*it + A - K) == abs(ans - K)) ans = min(ans, *it + A);
    }

    cout << ans << '\n';
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