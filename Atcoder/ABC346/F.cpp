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
string S, T;
vector<int> Sidx[26];

bool check(ll k) {
    ll cnt = 0, pos = -1;
    for(auto cc: T){
        int c = cc - 'a';
        if(Sidx[c].empty()) return false;
        auto it = upper_bound(Sidx[c].begin(), Sidx[c].end(), pos) - Sidx[c].begin();
        ll idx = k-1+it;
        cnt += idx / Sidx[c].size();
        pos = Sidx[c][idx % Sidx[c].size()];
        if(cnt >= N) return false;
    }
    return true;
}

void solve(){
    cin >> N;
    cin >> S >> T;
    int sl = S.length(), tl = T.length();
    for(int i = 0; i<sl; i++){
        Sidx[S[i] - 'a'].push_back(i);
    }
    ll ac = 0, wa = N*sl+1;
    while((wa - ac) > 1){
        ll wj = (ac + wa) / 2;
        if(check(wj)) ac = wj;
        else wa = wj;
    }
    cout << ac << '\n';
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