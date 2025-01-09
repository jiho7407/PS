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

const int MXSZ = 5000;

void solve(){
    string A, B; cin >> A >> B;
    int sz = A.size();
    bitset<MXSZ> S(B), T(A);

    vector<bitset<MXSZ>> shifts;
    rep(i, 0, sz){
        bitset<MXSZ> tmp;
        tmp |= (S << i);
        tmp |= (S >> (sz - i));
        tmp ^= (S >> (sz-i) << sz);
        // cout << tmp << endl;
        shifts.push_back(tmp);
    }

    rep(i, 0, sz) rep(j, i, sz){
        if((shifts[i]^shifts[j]) == T){
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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