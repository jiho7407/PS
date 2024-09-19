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
string S;
ll DP[200][200];
bool ovf[200][200];
const ll mod = 1e5;

int judge(char a, char b){
    if(a == '?'){
        if(b == '?') return 3;
        if(b == ')' || b == '}' || b == ']') return 1;
    }
    if(a == '('){
        if(b == '?' || b == ')') return 1;
    }
    if(a == '{'){
        if(b == '?' || b == '}') return 1;
    }
    if(a == '['){
        if(b == '?' || b == ']') return 1;
    }
    return 0;
}

ll calc(int l, int r){
    if(l > r) return 1;
    if(l == r) return 0;

    ll &ret = DP[l][r];
    if(ret != -1) return ret;

    if(r-l == 1){
        return ret = judge(S[l], S[r]);
    }

    ret = 0;
    rep(j, l+1, r+1){
        ll tmp = calc(l+1, j-1) * calc(j+1, r) * judge(S[l], S[j]);
        if(tmp){
            if(ovf[l+1][j-1] || ovf[j+1][r]) ovf[l][r] = 1;
        }
        ret += tmp;
        if(ret >= mod){
            ovf[l][r] = 1;
            ret %= mod;
        }
    }
    return ret;
}

void solve(){
    cin >> N >> S;
    fill_n(&DP[0][0], 200*200, -1);
    ll ans = calc(0, N-1);
    if(ovf[0][N-1]){
        cout << setw(5) << setfill('0') << ans % 100000 << '\n';
    }
    else cout << ans << '\n';
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