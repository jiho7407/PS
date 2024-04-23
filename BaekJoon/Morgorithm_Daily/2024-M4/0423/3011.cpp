#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
int P[101];
int A, B;

void solve(){
    cin >> N;
    rep(i, 1, N+1) cin >> P[i];
    sort(P+1, P+N+1);
    cin >> A >> B;
    if(!(A%2)) A++;
    if(!(B%2)) B--;

    int ans = -1, mx = 0;
    if(P[1]-A > mx){
        mx = P[1]-A;
        ans = A;
    }
    if(B-P[N] > mx){
        mx = B-P[N];
        ans = B;
    }
    rep(i, 1, N){
        if(P[i] > B || P[i+1] < A) continue;

        int mid = (P[i]+P[i+1])/2;
        if(!(mid%2)) mid--;

        if(A <= mid && mid <= B){
            int calc = min(mid-P[i], P[i+1]-mid);
            if(calc > mx){
                mx = calc;
                ans = mid;
            }
        }
        else if(mid < A){
            int calc = min(A-P[i], P[i+1]-A);
            if(calc > mx){
                mx = calc;
                ans = A;
            }
        }
        else{
            int calc = min(B-P[i], P[i+1]-B);
            if(calc > mx){
                mx = calc;
                ans = B;
            }
        }
    }
    cout << ans << '\n';
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