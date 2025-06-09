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
    string S; cin >> S;
    int h, m, s;
    h = stoi(S.substr(0, 2));
    m = stoi(S.substr(3, 2));
    s = stoi(S.substr(6, 2));
    string binh, binm, bins;
    binh = binm = bins = "";
    rep(i, 0, 6){
        binh += (h%2) ? '1' : '0';
        h /= 2;
    }
    rep(i, 0, 6){
        binm += (m%2) ? '1' : '0';
        m /= 2;
    }
    rep(i, 0, 6){
        bins += (s%2) ? '1' : '0';
        s /= 2;
    }
    reverse(binh.begin(), binh.end());
    reverse(binm.begin(), binm.end());
    reverse(bins.begin(), bins.end());
    // cout << binh << ' ' << binm << ' ' << bins << '\n';
    rep(i, 0, 6) cout << binh[i] << binm[i] << bins[i];
    cout << ' ';
    rep(i, 0, 6) cout << binh[i];
    rep(i, 0, 6) cout << binm[i];
    rep(i, 0, 6) cout << bins[i];
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