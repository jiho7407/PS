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

const int mxN = 100000;
int N;
vector<int> S, T;

void solve(){
    cin >> N;
    S.resize(N*2);
    T.resize(N);
    rep(i, 0, N) cin >> S[i];
    rep(i, 0, N) cin >> T[i];
    rep(i, 0, N) S[i+N] = S[i];

    vector<int> pi(N);
    for(int i = 1, j = 0; i < N; i++){
        while(j && T[i] != T[j]) j = pi[j-1];
        if(T[i] == T[j]) pi[i] = ++j;
    }

    vector<int> kmp(N*2);
    for(int i = 0, j = 0; i < N*2; i++){
        while(j && S[i] != T[j]) j = pi[j-1];
        if(S[i] == T[j]){
            if(j == N-1){
                cout << "YES";
                return;
            }
            else j++;
        }
    }
    cout << "NO";
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