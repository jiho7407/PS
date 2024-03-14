#include <bits/stdc++.h>
using namespace std;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, X, Y, x, y;

int main(){
    fastio();
    cin >> N;
    while(N--){
        cin >> X >> Y >> x >> y;
        int w1, w2, h1, h2;
        w1 = (X-1)/(x*2)+1;
        h1 = (Y-1)/(y*2)+1;
        x2 = x1, y2 = y1;
        if(X%x) x2--;
        if(Y%y) y2--;

        int ans = 0;

        ans += max(w1*h1, w2*h2)
    }
    return 0;
}