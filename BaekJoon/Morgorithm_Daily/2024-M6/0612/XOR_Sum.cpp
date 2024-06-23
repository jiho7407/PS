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

void solve(){
    int N, K; cin >> N >> K;
    int res = 0;
    multiset<int> ms;
    while(N--){
        string op; cin >> op;
        if(op == "insert"){
            int x; cin >> x;
            if(ms.size() < K){
                ms.insert(x);
                res ^= x;
            }
            else{
                if(x > *ms.begin()){
                    res ^= *ms.begin();
                    ms.erase(ms.begin());
                    ms.insert(x);
                    res ^= x;
                }
            }
        }
        else{
            cout << res << '\n';
        }
    }
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