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
    int x, y; cin >> x >> y;
    bool rev = false;
    if(x > y){
        swap(x, y);
        rev = true;
    }
    int dif = y-x;
    while(dif && !(dif%2)) dif/=2;
    rep(i, 0, 5){
        int a, b; cin >> a >> b;
        if(rev) swap(a, b);
        if(dif == 0){
            if(a==b) cout << "Y\n";
            else cout << "N\n";
        }
        else{
            if(a>=b) cout << "N\n";
            else{
                if((b-a)%dif) cout << "N\n";
                else cout << "Y\n";
            }
        }
    }
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