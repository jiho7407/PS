#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

const double pi = 3.14159265358979323846;
double M, N;
double R;
double ax, ay, bx, by;

void solve(){
    cin >> M >> N >> R;
    cin >> ax >> ay >> bx >> by;
    double uy = R/N;
    double ans = 123456789;
    for(int i = 0; i <= max(ay, by); i++){
        ans = min(ans, i * uy * pi * (abs(ax-bx)/M) + uy*(abs(ay-i) + abs(by-i)));
    }
    cout << fixed << setprecision(14);
    cout << ans; 
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}