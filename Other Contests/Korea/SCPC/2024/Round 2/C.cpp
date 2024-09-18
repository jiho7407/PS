#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
vector<tii> evt;
double P[100000];

vector<int> Xs, Ys;
double XP[100001], RXP[100001], BXP[100001], YP[100001], RYP[100001], BYP[100001];

bool cmp1(tii a, tii b){
    return get<0>(a) < get<0>(b);
}

bool cmp2(tii a, tii b){
    return get<1>(a) < get<1>(b);
}

void solve(){
    evt.clear();
    Xs.clear();
    Ys.clear();
    fill(XP, XP+100001, 0);
    fill(RXP, RXP+100001, 0);
    fill(BXP, BXP+100001, 0);
    fill(YP, YP+100001, 0);
    fill(RYP, RYP+100001, 0);
    fill(BYP, BYP+100001, 0);

    cin >> N;
    rep(i, 0, N){
        int x, y; cin >> x >> y;
        Xs.push_back(x);
        Ys.push_back(y);
        evt.push_back({x, y, i});
    }
    Xs.push_back(-1e7);
    Xs.push_back(1e7);
    Ys.push_back(-1e7);
    Ys.push_back(1e7);
    sort(Xs.begin(), Xs.end());
    sort(Ys.begin(), Ys.end());

    rep(i, 0, N) cin >> P[i];

    sort(evt.begin(), evt.end(), cmp1);
    rep(i, 1, N+1) XP[i] = XP[i-1] - P[get<2>(evt[i-1])]*get<0>(evt[i-1]);
    for(int i = N-1; i>=0; i--) RXP[i] = RXP[i+1] + P[get<2>(evt[i])]*get<0>(evt[i]);
    rep(i, 1, N+1) BXP[i] = BXP[i-1] + P[get<2>(evt[i-1])];

    sort(evt.begin(), evt.end(), cmp2);
    rep(i, 1, N+1) YP[i] = YP[i-1] - P[get<2>(evt[i-1])]*get<1>(evt[i-1]);
    for(int i = N-1; i>=0; i--) RYP[i] = RYP[i+1] + P[get<2>(evt[i])]*get<1>(evt[i]);
    rep(i, 1, N+1) BYP[i] = BYP[i-1] + P[get<2>(evt[i-1])];

    cin >> M;
    cout << fixed << setprecision(10);
    while(M--){
        int x, y; cin >> x >> y;
        int xidx = upper_bound(Xs.begin(), Xs.end(), x) - Xs.begin()-1;
        int yidx = upper_bound(Ys.begin(), Ys.end(), y) - Ys.begin()-1;
        double ans = 0;
        ans += XP[xidx] + RXP[xidx] + (BXP[xidx]*2 - 1)*x;
        ans += YP[yidx] + RYP[yidx] + (BYP[yidx]*2 - 1)*y;
        cout << ans << '\n';
    }
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