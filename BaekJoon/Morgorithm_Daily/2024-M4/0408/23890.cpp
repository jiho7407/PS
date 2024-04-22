#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}
ll R;

void solve(){
    cin >> R;
    ll x=1, y=R-1LL;
    while(x*x + y*y < R*R) x++;
    x--;
    cout << x << " " << y << '\n';
    return;
}

int main(){
    fastio();
    solve();
    return 0;
}