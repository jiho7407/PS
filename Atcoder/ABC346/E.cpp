#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

ll H, W, M;
ll colors[200005];
vector<tuple<ll, ll, ll>> query;

void solve(){
    cin >> H >> W >> M;
    fill(colors, colors + 200005, 0);
    for(ll i = 0; i<M; i++){
        ll T, A, X;
        cin >> T >> A >> X;
        A--;
        query.push_back({T, A, X});
    }
    ll crow = 0, ccol = 0;
    bool cdrow[200005], cdcol[200005];
    fill(cdrow, cdrow + H, false);
    fill(cdcol, cdcol + W, false);
    for(ll i = M-1; i>=0; i--){
        ll T, A, X;
        tie(T, A, X) = query[i];
        if(T == 1){
            if(cdrow[A]) continue;
            cdrow[A] = true;
            colors[X] += W-ccol;
            crow++;
        }
        else{
            if(cdcol[A]) continue;
            cdcol[A] = true;
            colors[X] += H-crow;
            ccol++;
        }
    }
    ll anscnt = 0, anssum = 0;
    for(ll i = 1; i<200005; i++){
        if(colors[i] == 0) continue;
        anscnt++;
        anssum += colors[i];
    }
    if(anssum < H*W){
        anscnt++;
        colors[0] = H*W - anssum;
    }
    cout << anscnt << '\n';
    for(ll i = 0; i<200005; i++){
        if(colors[i] == 0) continue;
        cout << i << ' ' << colors[i] << '\n';
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