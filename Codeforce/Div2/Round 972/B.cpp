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

int N, M, Q;
vector<int> V;

void solve(){
    cin >> N >> M >> Q;
    V.resize(M);
    rep(i, 0, M) cin >> V[i];
    sort(V.begin(), V.end());
    while(Q--){
        int X; cin >> X;
        // 맨 왼쪽 선생님보다 왼쪽
        if(X < V[0]){
            cout << V[0] - 1 << '\n';
            continue;
        }
        // 맨 오른쪽 선생님보다 오른쪽
        if(X > V[M-1]){
            cout << N - V[M-1] << '\n';
            continue;
        }
        // 중간에 있는 경우
        int idx = upper_bound(V.begin(), V.end(), X) - V.begin();
        int gap = V[idx] - V[idx-1] - 1;
        cout << (gap+1)/2 << '\n';
    }
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