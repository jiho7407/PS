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

struct Box{
    int lx, ly, px, py;
};
bool operator<(Box a, Box b){
    return false;
}

int Lx, Ly, N;
multiset<pair<int, Box>> s;

bool inter(Box a, Box b){
    if(a.px + a.lx <= b.px || b.px + b.lx <= a.px) return false;
    if(a.py + a.ly <= b.py || b.py + b.ly <= a.py) return false;
    return true;
}

void solve(){
    cin >> Lx >> Ly >> N;
    rep(i, 0, N){
        Box a;
        int h;
        cin >> a.lx >> a.ly >> h >> a.px >> a.py;
        for(auto idx = s.rbegin(); idx != s.rend(); idx++){
            Box b = idx->second;
            if(inter(a, b)){
                h += idx->first;
                break;
            }
        }
        s.insert({h, a});

        // for(auto [h, b] : s){
        //     cout << h << ' ' << b.lx << ' ' << b.ly << ' ' << b.px << ' ' << b.py << '\n';
        // }
        // cout << '\n';
    }
    cout << s.rbegin()->first;
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