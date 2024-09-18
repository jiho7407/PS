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

tuple<ld, ld, ld> points[3];
ld lenn[3];
ld V[3];
int W[3];
ld ans[3];

void rotate(){
    tuple<ld, ld, ld> tmp = points[0];
    points[0] = points[1];
    points[1] = points[2];
    points[2] = tmp;

    int tmp2 = W[0];
    W[0] = W[1];
    W[1] = W[2];
    W[2] = tmp2;

    ld tmp3 = ans[0];
    ans[0] = ans[1];
    ans[1] = ans[2];
    ans[2] = tmp3;
}

ld dist(pair<ld, ld> A, pair<ld, ld> B){
    return sqrt((A.first-B.first)*(A.first-B.first) + (A.second-B.second)*(A.second-B.second));
}

void solve(){
    rep(i, 0, 3){
        ld x, y, v;
        cin >> x >> y >> v;
        points[i] = {x, y, v};
    }
    rep(i, 0, 3) cin >> W[i];

    int rot = 0;
    while(get<2>(points[2]) != 0){
        // 3번째가 0일때까지 회전
        rotate();
        rot++;
    }

    rep(i, 0, 3){
        int j = (i+1)%3;
        auto [x1, y1, v1] = points[i];
        auto [x2, y2, v2] = points[j];
        lenn[i] = dist({x1, y1}, {x2, y2});
    }

    if(get<2>(points[0]) > get<2>(points[1])){
        // 빠른 차가 1번 점
        auto [x1, y1, v1] = points[0];
        auto [x2, y2, v2] = points[1];

        ans[1] = (lenn[0] + lenn[1] + lenn[2]) / v2;

        // 만날때까지 빠른차가 간 거리, 시간
        ld D = (v1*lenn[0])/(v1 - v2);
        ld t = D / v1;

        if(D < lenn[0] + lenn[1] && W[1] == 1){ // P2~P3에서 만남
            ld ret = 0;
            ret += D / v1;
            ret += (lenn[0] + lenn[1] - D) / v2;
            ret += lenn[2] / v1;
            ans[0] = ret;
        }
        else if(lenn[0] + lenn[1] < D && D < lenn[0] + lenn[1] + lenn[2] && W[2] == 1){ // P3~P1에서 만남
            ld ret = 0;
            ret += D / v1;
            ret += (lenn[0] + lenn[1] + lenn[2] - D) / v2;
            ans[0] = ret;
        }
        else ans[0] = (lenn[0] + lenn[1] + lenn[2]) / v1;
    }
    else{
        // 빠른 차가 2번 점, v1 < v2
        auto [x1, y1, v1] = points[0];
        auto [x2, y2, v2] = points[1];

        ans[0] = (lenn[0] + lenn[1] + lenn[2]) / v1;

        // 만날때까지 느린차가 간 거리, 시간
        ld D = ((lenn[1] + lenn[2])*v1)/(v2 - v1);
        ld t = D / v1;

        if(D < lenn[0] && W[0] == 1){ // P1~P2에서 만남
            ld ret = 0;
            ret += (D + lenn[1] + lenn[2]) / v2;
            ret += (lenn[0] - D) / v1;
            ans[1] = ret;
        }
        else ans[1] = (lenn[0] + lenn[1] + lenn[2]) / v2;
    }

    rep(i, 0, 3 - rot) rotate();
    rep(i, 0, 3){
        if(get<2>(points[i]) == 0) cout << "-\n";
        else cout << fixed << setprecision(10) << ans[i] << '\n';
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
