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

int N;
int A, B;
int nxt[100001];
set<pii> s;

int calc(int A, int B){
    if(A == B) return 0;
    else if(nxt[B] == A) return 0;
    else if(nxt[A] == B) return 1;

    if(s.find({A, B}) != s.end()) return 2;
    s.insert({A, B});
    
    int ret = calc(nxt[B], A);
    if(ret == 2) return 2;
    return 1-ret;
}

void solve(){ 
    cin >> N;
    cin >> A >> B;
    rep(i, 1, N+1) cin >> nxt[i];

    if(N == 2){
        if(A == B) cout << "first";
        else cout << "second";
        return;
    }

    if(N%2){
        if(A == B || nxt[B] == A) cout << "second";
        else cout << "first";
    }
    else{
        int ret = calc(A, B);
        if(ret == 0) cout << "first";
        else if(ret == 1) cout << "second";
        else cout << "drarw";
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