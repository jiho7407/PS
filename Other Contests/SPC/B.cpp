#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(int i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;
string S;
int cnt[26];

void solve(){
    cin >> N >> M;
    cin >> S;
    rep(i, 0, N){
        cnt[S[i]-'a']++;
    }
    int idx = 0;
    rep(i, 0, M){
        while(cnt[idx] <= 0) idx++;
        cnt[idx]--;
    }
    
    string T;
    for(int i = N-1; i >= 0; i--){
        if(cnt[S[i]-'a'] > 0){
            T += S[i];
            cnt[S[i]-'a']--;
        }
    }
    reverse(T.begin(), T.end());
    cout << T << '\n';
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