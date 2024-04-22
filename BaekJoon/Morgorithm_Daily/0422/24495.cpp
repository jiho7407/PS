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

int A[4], B[4], C[4];

bool comp(int A[], int B[]){
    int a = 0, b = 0;
    rep(i, 0, 4) rep(j, 0, 4) {
        if(A[i] > B[j]) a++;
        else if(A[i] < B[j]) b++;
    }
    return a>b;
}

void solve(){
    rep(i, 0, 4) cin >> A[i];
    rep(i, 0, 4) cin >> B[i];
    if(!comp(A, B)) swap(A, B);
    rep(p, 1, 11) rep(q, 1, 11) rep(r, 1, 11) rep(s, 1, 11){
        C[0] = p; C[1] = q; C[2] = r; C[3] = s;
        if(comp(A, B) && comp(B, C) && comp(C, A)){
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
    return;
}

int main(){
    fastio();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}