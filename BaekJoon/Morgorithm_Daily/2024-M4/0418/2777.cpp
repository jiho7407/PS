#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    int N; cin >> N;
    if(N==1) {
        cout << 1 << '\n';
        return;
    }
    int cnt = 0;
    for(int i = 9; i>=2; i--){
        while(N%i == 0){
            N /= i;
            cnt++;
        }
    }
    if(N == 1) cout << cnt << '\n';
    else cout << -1 << '\n';
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}