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

int calc(ll tp, ll bt){
    if(tp == 1 && bt == 1) return 1;
    if(tp < bt) return 2*calc(tp, bt-tp);
    else return 2*calc(tp-bt, bt)+1;
}

void solve(){
    int N; cin >> N; cout << N << ' ';

    string S; cin >> S;
    string tp = "", bt = "";
    bool istp = true;
    for(auto c: S){
        if(c == '/') istp = false;
        else if(istp) tp += c;
        else bt += c;
    }

    cout << calc(stoll(tp), stoll(bt)) << '\n';
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