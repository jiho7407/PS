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
    string S; cin >> S;
    int N = S.size();
    int idx = 0;
    bool flag = true;
    while(idx < N){
        if(S[idx] == 'p'){
            if(idx+1 < N && S[idx+1] == 'i'){
                idx += 2;
            }else{
                flag = false;
                break;
            }
        }
        else if(S[idx] == 'k'){
            if(idx+1 < N && S[idx+1] == 'a'){
                idx += 2;
            }else{
                flag = false;
                break;
            }
        }
        else if(S[idx] == 'c'){
            if(idx+2 < N && S[idx+1] == 'h' && S[idx+2] == 'u'){
                idx += 3;
            }else{
                flag = false;
                break;
            }
        }
        else{
            flag = false;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << '\n';
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