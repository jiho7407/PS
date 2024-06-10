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

void printer(int a, int b, int cnt){
    while(cnt--){
        cout << a << " " << b << "\n";
        swap(a, b);
    }
}

queue<tuple<vector<int>, pii, vector<pii>>> q; // (숙우1 숙우2 숙우3) (이동1 이동2) 경로

void solve(){
    int N; cin >> N;
    int T1, T2; cin >> T1 >> T2;
    int M1 = (100-T1)/5, M2 = (100-T2)/5;
    vector<int> A(N), G(N);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) G[A[i]] = i+1;
    int parity = 0;
    rep(i, 0, N) rep(j, i+1, N){
        if(A[i]>A[j]) parity++;
    }
    if(parity%2 != (M1+M2)%2) { cout << -1; return; }
    if(M1 == 0 && A[0] != 1) { cout << -1; return; }
    if(M2 == 0 && A[1] != 2) { cout << -1; return; }
    if(M1 == 1 && A[0] == 1) { cout << -1; return; }
    if(M2 == 1 && A[1] == 2) { cout << -1; return; }
    cout << M1+M2 << "\n";
    q.push(make_tuple(vector<int>{3, 1, 2}, pii{0, 0}, vector<pii>{}));
    while(!q.empty()){
        auto [curA, curM, path] = q.front(); q.pop();
        // rep(i, 0, 3) cout << curA[i] << " ";
        // cout << curM.first << " " << curM.second << "\n";

        if(curM.first > M1 || curM.second > M2) continue;
        if(curA == G && (M1-curM.first)%2==0 && (M2-curM.second)%2==0){
            for(auto p : path) cout << p.first << " " << p.second << "\n";
            printer(curA[1], curA[0], M1-curM.first);
            printer(curA[2], curA[0], M2-curM.second);
            return;
        }
        path.push_back((pii){curA[1], curA[0]});
        q.push(make_tuple(vector<int>{curA[1], curA[0], curA[2]}, pii{curM.first+1, curM.second}, path));
        path.pop_back();
        path.push_back((pii){curA[2], curA[0]});
        q.push(make_tuple(vector<int>{curA[2], curA[1], curA[0]}, pii{curM.first, curM.second+1}, path));
        path.pop_back();
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