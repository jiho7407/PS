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

void solve(){
    int K; cin >> K;
    string S, T; cin >> S >> T;
    if(S.size() > T.size()) swap(S, T);

    // 차이가 2 이상
    if(T.size() - S.size() >= 2){
        cout << "No";
        return;
    }

    // 길이 차이가 1
    if(T.size() - S.size() == 1){
        int sidx = 0, tidx = 0;
        bool used = false;
        while(sidx < S.size() && tidx < T.size()){
            if(S[sidx] != T[tidx]){
                if(used){
                    cout << "No";
                    return;
                }
                used = true;
                tidx++;
            }
            else{
                sidx++;
                tidx++;
            }
        }
        cout << "Yes";
        return;
    }

    // 길이 차이가 0
    if(T.size() - S.size() == 0){
        int diff = 0;
        rep(i, 0, S.size()){
            if(S[i] != T[i]) diff++;
        }
        if(diff <= 1){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
        return;
    }

    assert(false);
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