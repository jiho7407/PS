#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
string S;
int pi[1000001];

void solve(){
    cin >> N >> S;
    fill(pi, pi+N, 0);
    int j = 0;
    for(int i = 1; i<N; i++){
        while(j>0 && S[i] != S[j]) j = pi[j-1];
        if(S[i] == S[j]) pi[i] = ++j;
    }
    cout << N - pi[N-1];
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