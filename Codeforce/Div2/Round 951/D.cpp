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

int N, K;
string S;

bool check(int idx){
    string T;
    T += S.substr(0, idx);
    string tmp = S.substr(idx);
    reverse(tmp.begin(), tmp.end());
    T += tmp;
    // cout << "checked " << T << " " << idx << "\n";
    rep(i, 0, N/K){
        rep(j, 0, K){
            if(i%2 == 0 && T[i*K+j] == '1') return false;
            if(i%2 == 1 && T[i*K+j] == '0') return false;
        }
    }
    return true;
}

void solve(){
    cin >> N >> K;
    cin >> S;
    if(S[0] == '1'){
        rep(i, 0, N){
            if(S[i] == '0') S[i] = '1';
            else S[i] = '0';
        }
    }
    int zcnt = 0, ocnt = 0;
    int block = 0, idx = 0;
    while(idx<N){
        if(block == 0){
            while(idx<N && S[idx] == '0'){
                zcnt++;
                idx++;
            }
            if(zcnt < K){
                if(check(idx)) cout << idx << "\n";
                else cout << "-1\n";
                return;
            }
            if(zcnt > K){
                if(check(idx - K)) cout << idx - K << "\n";
                else cout << "-1\n";
                return;
            }
            block = 1;
            zcnt = 0;
        }
        else{
            while(idx<N && S[idx] == '1'){
                ocnt++;
                idx++;
            }
            if(ocnt < K){
                if(check(idx)) cout << idx << "\n";
                else cout << "-1\n";
                return;
            }
            if(ocnt > K){
                if(check(idx - K)) cout << idx - K << "\n";
                else cout << "-1\n";
                return;
            }
            block = 0;
            ocnt = 0;
        }
    }
    if(check(N)) cout << N << "\n";
    else cout << "-1\n";
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