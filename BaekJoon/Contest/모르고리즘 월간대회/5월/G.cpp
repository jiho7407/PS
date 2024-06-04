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

const int mxN = 2000;
int N, A[mxN];
bool anslink[mxN][mxN];

void solve(){
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    fill_n(anslink[0], mxN*mxN, 0);
    rep(i, 0, N){
        priority_queue<pii> pq; // 간선개수, 정점번호
        rep(j, i+1, N) pq.push({A[j], j});
        while(A[i]){
            if(pq.empty()){
                cout << -1;
                return;
            }
            if(pq.top().first == 0){
                cout << -1;
                return;
            }
            int j = pq.top().second;
            pq.pop();
            anslink[i][j] = anslink[j][i] = 1;
            A[i]--; A[j]--;
        }
    }
    rep(i, 0, N){
        rep(j, 0, N) cout << anslink[i][j] << ' ';
        cout << '\n';
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