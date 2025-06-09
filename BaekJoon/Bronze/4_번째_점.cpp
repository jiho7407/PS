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

double v[8];
pair<double, double> p[4];

void solve(){
    while(1){
        rep(i, 0, 8){
            if(cin.eof()) return;
            cin >> v[i];
        }
        rep(i, 0, 4){
            p[i] = {v[i*2], v[i*2+1]};
        }
        if(p[0] == p[3]) swap(p[2], p[3]);
        if(p[1] == p[2]) swap(p[0], p[1]);
        if(p[1] == p[3]) swap(p[0], p[1]), swap(p[2], p[3]);
        cout << fixed << setprecision(3);
        cout << p[3].first + (p[1].first - p[0].first) << ' ' << p[3].second + (p[1].second - p[0].second) << '\n';
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