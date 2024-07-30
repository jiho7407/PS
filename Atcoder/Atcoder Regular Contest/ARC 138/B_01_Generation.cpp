#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
deque<bool> dq;
bool inv = false;

void solve(){
    cin >> N;
    dq.resize(N);
    rep(i, 0, N) cin >> dq[i];

    while(!dq.empty()){
        if(dq.back() == inv) dq.pop_back();
        else if(dq.front() == inv){
            dq.pop_front();
            inv = !inv;
        }
        else break;
    }

    if(dq.size() == 0) cout << "Yes\n";
    else cout << "No\n";
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