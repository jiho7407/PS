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

void sol3(int s, int e){
    int m = 6-s-e;
    cout << 7 << "\n";
    cout << s << ' ' << e << "\n";
    cout << s << ' ' << m << "\n";
    cout << e << ' ' << m << "\n";
    cout << s << ' ' << e << "\n";
    cout << m << ' ' << s << "\n";
    cout << m << ' ' << e << "\n";
    cout << s << ' ' << e << "\n";
}

void solve(){
    int k, s, e; cin >> k >> s >> e;
    if(k==3){ sol3(s, e); return; }
    cout << 2*(k-1)*(k-1)-1 << "\n";
    vector<int> pos;
    rep(i, 1, k+1){
        if(i!=s && i!=e) pos.push_back(i);
    }
    rep(i, 0, pos.size()){
        cout << s << ' ' << e << "\n";
        for(int j = pos.size()-1; j>=i; j--){
            cout << s << ' ' << pos[j] << "\n";
        }
        for(int j = i+1; j<pos.size(); j++){
            cout << pos[j] << ' ' << pos[i] << "\n";
        }
        cout << e << ' ' << pos[i] << "\n";
    }
    cout << s << ' ' << e << "\n";
    for(int i = pos.size()-1; i>=0; i--){
        cout << pos[i] << ' ' << s << "\n";
        for(int j = pos.size()-1; j>i; j--){
            cout << pos[i] << ' ' << pos[j] << "\n";
        }
        for(int j = i; j<pos.size(); j++){
            cout << pos[j] << ' ' << e << "\n";
        }
        cout << s << ' ' << e << "\n";
    }
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