#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;

ll mx = 1e9+1;

void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

bool solve(){
    ll okb = 0, ngb = mx;
    while(ngb - okb > 1){
        ll mid = (okb + ngb) / 2;
        cout << "?" << " " << 0 << " " << mid << "\n";
        cout.flush();
        string res;
        cin >> res;
        if(res=="!") return false;
        if(res == "-") ngb = mid;
        else okb = mid;
    }
    ll oka = 0, nga = 2*okb+1;
    while(nga - oka > 1){
        ll mid = (oka + nga) / 2;
        cout << "?" << " " << mid << " " << okb << "\n";
        cout.flush();
        string res;
        cin >> res;
        if(res=="!") return false;
        if(res=="0"){
            oka = mid;
            break;
        }
        if(res == "+") oka = mid;
        else nga = mid;
    }
    cout << "! " << okb*okb + oka << "\n";
    cout.flush();
    return true;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        if(!solve()) break;
    }
    return 0;
}