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

int N, M;
string S, T;
ll alp[26];
const ll P = 1e15+37;
unordered_set<ll> st;

void solve(){
    cin >> S >> T;
    if(S.size() > T.size()) swap(S, T);
    N = S.size(); M = T.size();

    alp[0] = 1;
    rep(i, 1, 26) alp[i] = alp[i-1]*2000%P;

    for(int ln = N-1; ln >= 0; ln--){
        ll tmp = 0;
        rep(i, 0, ln+1){
            tmp += alp[S[i]-'a'];
            tmp %= P;
        }
        st.insert(tmp);
        rep(i, ln+1, N){
            tmp -= alp[S[i-ln-1]-'a'];
            tmp += alp[S[i]-'a'];
            tmp = (tmp+P)%P;
            st.insert(tmp);
        }

        tmp = 0;
        rep(i, 0, ln+1){
            tmp += alp[T[i]-'a'];
            tmp %= P;
        }
        if(st.count(tmp)){ cout << ln+1; return; }
        rep(i, ln+1, M){
            tmp -= alp[T[i-ln-1]-'a'];
            tmp += alp[T[i]-'a'];
            tmp = (tmp+P)%P;
            if(st.count(tmp)){ cout << ln+1; return; }
        }
        st.clear();
    }
    cout << 0;
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