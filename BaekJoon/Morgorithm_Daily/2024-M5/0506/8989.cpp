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

bool cmp(string a, string b){
    int ah = stoi(a.substr(0, 2)), am = stoi(a.substr(3, 2));
    int bh = stoi(b.substr(0, 2)), bm = stoi(b.substr(3, 2));
    if(ah >= 12) ah -= 12;
    if(bh >= 12) bh -= 12;
    double ahth = ah*30 + (double)am/2, amth = am*6;
    double bhth = bh*30 + (double)bm/2, bmth = bm*6;
    double adiff = min(abs(ahth - amth), 360 - abs(ahth - amth));
    double bdiff = min(abs(bhth - bmth), 360 - abs(bhth - bmth));
    if(adiff == bdiff) return a < b;
    return adiff < bdiff;
}

void solve(){
    vector<string> clock;
    string s;
    rep(i, 0, 5){
        cin >> s;
        clock.push_back(s);
    }
    sort(clock.begin(), clock.end(), cmp);
    cout << clock[2] << '\n';
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