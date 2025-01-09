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

ll DPcnt[18][2], DPsum[18][2];
/*
DP[i][j]
i: 결정된 자릿수
j: tight 여부
*/
ll calc(ll N){
    if(N<=0) return 0;
    vector<int> digit;
    while(N){
        digit.push_back(N%10);
        N/=10;
    }
    reverse(digit.begin(), digit.end());
    int n = digit.size();

    fill_n(&DPcnt[0][0], 18*2, 0);
    fill_n(&DPsum[0][0], 18*2, 0);
    
    rep(d, 0, digit[0]+1){
        int nt = (d == digit[0]) ? 1 : 0;
        DPcnt[1][nt] += 1;
        DPsum[1][nt] += d;
    }

    rep(i, 1, n) rep(tight, 0, 2) {
        ll &cnt = DPcnt[i][tight];
        ll &sum = DPsum[i][tight];
        rep(k, 0, 10){
            if(tight && digit[i]<k) break;
            int tn = tight && (digit[i]==k);
            DPcnt[i+1][tn] += cnt;
            DPsum[i+1][tn] += sum + k*cnt;
        }
    }

    ll ret = 0;
    rep(i, 0, 2) ret += DPsum[n][i];
    return ret;
}

void solve(){
    ll L, R; cin >> L >> R;
    cout << calc(R) - calc(L-1) << '\n';
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    rep(TC, 1, tc+1){1
        solve();
    }
    return 0;
}