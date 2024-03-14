#include <bits/stdc++.h>
using namespace std;

typedef tuple<double, double, double, double> box;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
double ans;
vector<box> lst;

void solve(box old, int cur, int cnt){
    auto [x, y, w, h] = old;
    auto [cx, cy, cw, ch] = lst[cur];
    if(cx+cw<x || x+w<cx || cy+ch<y || y+h<cy) return;
    double nx, ny, nw, nh;
    nx = max(x, cx);
    ny = max(y, cy);
    nw = min(x+w, cx+cw) - nx;
    nh = min(y+h, cy+ch) - ny;
    if(cnt%2) ans -= nw*nh;
    else ans += nw*nh;
    for(int i = cur+1; i<N; i++) solve(tuple(nx, ny, nw, nh), i, cnt+1);
}

int main(){
    fastio();
    cin >> N;
    double x, y, w, h;
    for(int i = 0; i<N; i++){
        cin >> x >> y >> w >> h;
        lst.push_back(tuple(x, y, w, h));
    }
    ans = 0;
    for(int i = 0; i<N; i++) solve(tuple(0, 0, 2000, 2000), i, 0);
    cout << fixed << setprecision(2);
    if(ans == static_cast<int>(ans)) { // 정수인 경우
        cout << static_cast<int>(ans) << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}