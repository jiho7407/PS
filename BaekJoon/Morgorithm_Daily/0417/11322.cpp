#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll N;
vector<ll> Xs;

void calc(){
    Xs.push_back(0);
    for(ll i = 1; i<=1e18; i*=10){
        int sz = Xs.size();
        for(ll j = 0; j<sz; j++){
            Xs.push_back(Xs[j]+i);
        }
    }
}

void solve(){
    cin >> N;
    for(ll X: Xs){
        if(X == 0) continue;
        if(X%N == 0){
            cout << X << "\n";
            return;
        }
    }
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    calc();
    while(tc--){
        solve();
    }
    return 0;
}