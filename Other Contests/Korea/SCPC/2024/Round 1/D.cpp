#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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

int N, L;
int A[100000], B[100000];
vector<int> idx; // 불가능한 쌍

void solve(){
    cin >> N >> L;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    sort(A, A+N); sort(B, B+N);

    // 불가능한 경우 처리
    int tmp = 0;
    rep(i, 0, N) tmp = max(tmp, abs(A[i]-B[i]));
    if(tmp > L){ cout << -1 << '\n'; return; }

    int ans = tmp;

    idx.clear();
    idx.push_back(-1);
    rep(i, 0, N-1) if(abs(A[i+1]-B[i]) > L) idx.push_back(i);
    idx.push_back(N-1);
    rep(i, 0, idx.size()-1){
        rep(j, idx[i]+1, idx[i+1]+1){
            int ok = j, ng = idx[i+1]+1;
            while(ng-ok > 1){
                int mid = (ok+ng)/2;
                if(abs(A[j] - B[mid]) <= L) ok = mid;
                else ng = mid;
            }
            ans = max(ans, abs(A[j] - B[ok]));
        }
    }

    swap(A, B); // 뒤집어서 똑같이
    idx.clear();
    idx.push_back(-1);
    rep(i, 0, N-1) if(abs(A[i+1]-B[i]) > L) idx.push_back(i);
    idx.push_back(N-1);
    rep(i, 0, idx.size()-1){
        rep(j, idx[i]+1, idx[i+1]+1){
            int ok = j, ng = idx[i+1]+1;
            while(ng-ok > 1){
                int mid = (ok+ng)/2;
                if(abs(A[j] - B[mid]) <= L) ok = mid;
                else ng = mid;
            }
            ans = max(ans, abs(A[j] - B[ok]));
        }
    }

    cout << ans << '\n';
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    rep(TC, 1, tc+1){
        cout << "Case #" << TC << '\n';
        solve();
    }
    return 0;
}