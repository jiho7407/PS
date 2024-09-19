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

int cnt[26];

void solve(){
    int N; cin >> N;
    string S; cin >> S;
    fill(cnt, cnt+26, 0);
    for(auto c : S){
        cnt[c-'a']++;
    }
    int cntt = 0;
    int idx = 0;
    while(cntt < N){
        while(cnt[idx] == 0) idx = (idx+1)%26;
        cout << (char)('a'+idx);
        cnt[idx]--;
        cntt++;
        idx = (idx+1)%26;
    }
    cout << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        solve();
    }
    return 0;
}