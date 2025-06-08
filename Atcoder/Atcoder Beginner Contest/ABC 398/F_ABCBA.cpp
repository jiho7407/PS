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

const int mxN = 1e6+1;
struct Manacher{
    int N, r = 0, p = 0;
    int A[mxN];
    Manacher(string T){
        string S = "#";
        for(auto c : T){ S += c; S += '#'; }

        N = S.size();
        rep(i, 0, N){
            if(i <= r) A[i] = min(A[2*p-i], r-i);
            else A[i] = 0;

            while(1){
                if(i-A[i]-1 < 0 || i+A[i]+1 >= N) break; // 범위 밖으로 나간 경우
                if(S[i-A[i]-1] != S[i+A[i]+1]) break; // 대칭이 아닌 경우
                A[i]++;
            }

            if(r < i+A[i]){
                r = i+A[i];
                p = i;
            }
        }
    }
};

void solve(){
    string S; cin >> S;
    string T = S;
    reverse(T.begin(), T.end());
    Manacher M(T);
    // rep(i, 0, M.N) cout << M.A[i] << ' '; cout << '\n';
    int mx = 0;
    rep(i, 0, M.N){
        if(i == M.A[i]) mx = max(mx, i);
    }
    
    // cout << mx << '\n';
    int sz = S.size();
    cout << S;
    for(int i = sz-mx-1; i >= 0; i--) cout << S[i];
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