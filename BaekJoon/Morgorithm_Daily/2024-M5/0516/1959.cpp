#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

void solve(){
    ll M, N; cin >> M >> N;
    if(M<=N){
        cout << 2*M-2 << "\n";
        cout << M/2+1 << " ";
        if(M%2) cout << N-M/2;
        else cout << M/2;
    }
    else{
        cout << 2*N-1 << "\n";
        if(N%2) cout << M-N/2;
        else cout << N/2+1;
        cout << " " << (N+1)/2;
    }
    cout << "\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}