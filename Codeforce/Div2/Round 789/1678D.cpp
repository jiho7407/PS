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

int N, M;
string S;
int ans[1000000];

void solve(){
    cin >> N >> M >> S;
    fill(ans, ans+N*M, 0);

    int ocnt = 0;
    rep(i, 0, M){
        if(S[i] == '1') ocnt++;
        if(ocnt) ans[i] = 1;
        else ans[i] = 0;
    }
    rep(i, 1, N){
        rep(j, 0, M){
            if(S[i*M+j] == '1') ocnt++;
            if(S[(i-1)*M+j] == '1') ocnt--;
            if(ocnt) ans[i*M+j] = ans[(i-1)*M+j] + 1;
            else ans[i*M+j] = ans[(i-1)*M+j];
        }
    }

    vector<bool> row(M, false);
    int rowcnt = 0;
    rep(i, 0, N*M){
        if(S[i] == '1'){
            int r = i%M;
            if(!row[r]){
                row[r] = true;
                rowcnt++;
            }
        }
        ans[i] += rowcnt;
    }

    rep(i, 0, N*M) cout << ans[i] << ' ';
    cout << '\n';
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