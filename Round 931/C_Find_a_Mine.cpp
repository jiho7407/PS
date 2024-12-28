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
    int N, M; cin >> N >> M;
    int ret[4];

    cout << "? " << 1 << ' ' << 1 << endl;
    cin >> ret[0];

    cout << "? " << 1 << ' ' << M << endl;
    cin >> ret[1];

    cout << "? " << N << ' ' << 1 << endl;
    cin >> ret[2];

    pii ans1, ans2;
    ans1.first = (ret[0] + ret[1] + 1 - M)/2;
    ans1.second = ret[0] - ans1.first;

    ans2.second = (ret[0] + ret[2] + 1 - N)/2;
    ans2.first = ret[0] - ans2.second;

    if(ans1.first < 0 || ans1.second < 0){
        cout << "! " << ans2.first+1 << ' ' << ans2.second+1 << endl;
        return;
    }
    cout << "? " << ans1.first+1 << ' ' << ans1.second+1 << endl;
    cin >> ret[3];
    if(ret[3] == 0) cout << "! " << ans1.first+1 << ' ' << ans1.second+1 << endl;
    else cout << "! " << ans2.first+1 << ' ' << ans2.second+1 << endl;
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