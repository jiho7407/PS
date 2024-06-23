#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define ld long double
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N, M;

void solve(){
    cin >> N; vector<int> A(N); rep(i, 0, N) cin >> A[i];
    cin >> M; vector<int> B(M); rep(i, 0, M) cin >> B[i];
    vector<int> ans;

    int Aidx = 0, Bidx = 0;
    for(int i = 100; i >= 1; i--){
        while(1){
            int a = Aidx; while(a < N && A[a] != i) a++;
            int b = Bidx; while(b < M && B[b] != i) b++;
            if(a >= N || b >= M) break;
            ans.push_back(i);
            Aidx = a + 1;
            Bidx = b + 1;
        }
    }
    cout << ans.size() << '\n';
    for(auto x : ans) cout << x << ' ';
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