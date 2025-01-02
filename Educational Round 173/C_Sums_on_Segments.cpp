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
vector<int> A;

pii getmnMx(int l, int r){
    if(l>r) return {0, 0};
    int mn = 0, mx = 0;
    int curmn = 0, curmx = 0;
    rep(i, l, r+1){
        curmn = min(0, curmn+A[i]);
        curmx = max(0, curmx+A[i]);

        mn = min(mn, curmn);
        mx = max(mx, curmx);
    }

    return {mn, mx};
}

pii getmnMx2(int l, int r, bool rev){
    if(l>r) return {0, 0};

    int mn = 0, mx = 0;
    int curmn = 0, curmx = 0;
    if(rev){
        for(int i = r; i>=l; i--){
            curmn += A[i];
            curmx += A[i];
            mn = min(mn, curmn);
            mx = max(mx, curmx);
        }
    }
    else{
        for(int i = l; i<=r; i++){
            curmn += A[i];
            curmx += A[i];
            mn = min(mn, curmn);
            mx = max(mx, curmx);
        }
    }

    return {mn, mx};
}

void solve(){
    cin >> N;
    A.resize(N);
    rep(i, 0, N) cin >> A[i];

    int block = -1;
    rep(i, 0, N){
        if(A[i] != -1 && A[i] != 1){
            block = i;
            break;
        }
    }

    vector<int> ans;

    if(block == -1){
        pii ret = getmnMx(0, N-1);
        rep(i, ret.first, ret.second+1) ans.push_back(i);
    }
    else{
        pii ret1 = getmnMx(0, block-1);
        pii ret2 = getmnMx(block+1, N-1);
        rep(i, min(ret1.first, ret2.first), max(ret1.second, ret2.second)+1) ans.push_back(i);

        pii ret3 = getmnMx2(0, block-1, true);
        pii ret4 = getmnMx2(block+1, N-1, false);

        rep(i, ret3.first + ret4.first, ret3.second + ret4.second + 1) ans.push_back(A[block] + i);
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << '\n';
    for(auto x: ans) cout << x << ' ';
    cout << '\n';
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