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

int N;
vector<int> G, H;
int E[100001];

void solve(){
    cin >> N;
    string S; cin >> S;
    rep(i, 0, N){
        if(S[i] == 'G') G.push_back(i);
        else if(S[i] == 'H') H.push_back(i);
    }
    rep(i, 0, N){
        cin >> E[i];
        E[i]--;
    }
    int ans = 0;
    int Gleader = -1, Hleader = -1;
    if(E[G[0]] >= G[G.size()-1]) Gleader = G[0];
    if(E[H[0]] >= H[H.size()-1]) Hleader = H[0];
    if(Gleader != -1){
        rep(i, 0, Gleader){
            if(i == Hleader) continue;
            if(S[i] == 'H' && E[i] >= Gleader) ans++;
        }
    }
    if(Hleader != -1){
        rep(i, 0, Hleader){
            if(i == Gleader) continue;
            if(S[i] == 'G' && E[i] >= Hleader) ans++;
        }
    }
    if(Gleader != -1 && Hleader != -1) ans++;
    cout << ans << '\n';
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