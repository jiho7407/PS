#include <bits/stdc++.h>
#define ll long long
#define lll __int128
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
const int mxN = 5e6;
struct Manacher{
    int N, r = 0, p = 0;
    int A[mxN];
    Manacher(string S){ // S가 짝수일경우 #a#b#c# 꼴로 변환
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
    cin >> S;
    string T = "#";
    for(auto c : S){
        T += c;
        T += '#';
    }
    auto manacher = new Manacher(T);
    ll ans = 0;
    rep(i, 0, T.size()) ans += (manacher->A[i]+1)/2;
    cout << ans;
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