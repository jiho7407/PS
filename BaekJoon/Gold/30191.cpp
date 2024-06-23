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

int N;
string S;
string ans = "";

void solve(){
    cin >> N >> S;
    stack<char> st;
    for(int i = N-1; i >= 0; i--){
        char c = S[i];
        if(c == 'U'){
            if(st.empty() || st.top() == 'U'){
                ans += "SN";
                st.push('U');
            }
            else if(st.top() == 'S'){
                ans += "N";
                st.pop();
            }
        }
        else{
            if(st.empty() || st.top() == 'S'){
                ans += "UN";
                st.push('S');
            }
            else if(st.top() == 'U'){
                ans += "N";
                st.pop();
            }
        
        }
    }
    cout << ans.size() << '\n';
    cout << ans << '\n';
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