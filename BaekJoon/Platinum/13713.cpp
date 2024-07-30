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

string S;
struct Zarray{
    string S;
    int N;
    int Z[1000000];

    Zarray(string S): S(S){
        N = S.size();
        Z[0] = N;
        int l = 0, r = 0;
        rep(i, 1, N){
            if(i <= r) Z[i] = min(Z[i-l], r-i);
            while(i+Z[i] < N && S[Z[i]] == S[i+Z[i]]) Z[i]++;
            if(i>r) l = i;
            r = max(r, i+Z[i]-1);
        }
    }
};

void solve(){
    cin >> S;
    reverse(S.begin(), S.end());
    auto Zs = new Zarray(S);

    int Q; cin >> Q;
    while(Q--){
        int A; cin >> A;
        cout << Zs->Z[S.size()-A] << '\n';
    }
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