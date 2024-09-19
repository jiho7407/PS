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

int J, A;
vector<int> clothes;
bool used[1000000];

map<char, int> mp = {{'S', 0}, {'M', 1}, {'L', 2}};

void solve(){
    cin >> J >> A;
    rep(i, 0, J){
        char c; cin >> c;
        clothes.push_back(mp[c]);
    }

    int ans = 0;
    while(A--){
        char sz; int idx;
        cin >> sz >> idx; idx--;
        if(used[idx]) continue;
        if(mp[sz] <= clothes[idx]){
            ans++;
            used[idx] = true;
        }
    }
    cout << ans << '\n';
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