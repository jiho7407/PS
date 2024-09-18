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

int N, D;
vector<int> Ls, Rs;

void solve(){
    cin >> N >> D;

    int zrs = 0;
    rep(i, 0, N){
        int x; cin >> x;
        if(x == 0) zrs++;
        if(x < 0) Ls.push_back(-x);
        if(x > 0) Rs.push_back(x);
    }
    sort(Ls.begin(), Ls.end());
    sort(Rs.begin(), Rs.end());

    int ans = 0;
    // 왼쪽으로 쭉 가는 경우
    ans = max(ans, zrs + (int)(upper_bound(Ls.begin(), Ls.end(), D) - Ls.begin()));

    // 왼쪽으로 갔다가 오른쪽으로 가는 경우
    int Lsz = Ls.size();
    rep(i, 0, Lsz){
        int l = Ls[i];
        if(l*2 > D) break;
        int r = D - 2*l;
        ans = max(ans, zrs + (i+1) + (int)(upper_bound(Rs.begin(), Rs.end(), r) - Rs.begin()));
    }

    // swap해서 반대로
    swap(Ls, Rs);
    ans = max(ans, zrs + (int)(upper_bound(Ls.begin(), Ls.end(), D) - Ls.begin()));
    Lsz = Ls.size();
    rep(i, 0, Lsz){
        int l = Ls[i];
        if(l*2 > D) break;
        int r = D - 2*l;
        ans = max(ans, zrs + (i+1) + (int)(upper_bound(Rs.begin(), Rs.end(), r) - Rs.begin()));
    }

    cout << ans << '\n';

    Ls.clear();
    Rs.clear();
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
    }
    return 0;
}