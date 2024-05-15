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

void postorder(string S, string T){
    if(S.size() == 0) return;
    char root = S[0];
    int idx = T.find(root);
    postorder(S.substr(1, idx), T.substr(0, idx));
    postorder(S.substr(idx+1), T.substr(idx+1));
    cout << root;
    return;
}

void solve(){
    while(1){
        string S, T;
        cin >> S >> T;
        if(cin.eof()) break;
        postorder(S, T);
        cout << "\n";
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