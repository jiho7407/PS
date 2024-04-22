#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int ans = 0;
int A[10];

void btr(int cur, int score, int last, int llast){
    if(cur == 10){
        if(score >= 5) ans++;
        return;
    }
    for(int i = 1; i<=5; i++){
        if(llast == last && last == i) continue;
        if(i == A[cur]) btr(cur+1, score+1, i, last);
        else btr(cur+1, score, i, last);
    }
    return;
}

void solve(){
    for(int i = 0; i<10; i++) cin >> A[i];
    btr(0, 0, -1, -1);
    cout << ans;
    return;
}

int main(){
    fastio();
    int tc = 1;
    // cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}