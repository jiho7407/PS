#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    ll N;
    cin >> N;
    if(N == 1) cout << 1;
    else cout << int(log2((long double)(N - 1)))+2;



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}