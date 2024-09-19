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

void solve(){
    int N; cin >> N;
    vector<int> lst;
    int tmp = N;
    while(tmp){
        lst.push_back(tmp%10);
        tmp /= 10;
    }
    sort(lst.begin(), lst.end());
    do{
        string s = "";
        for (auto it = lst.begin(); it != lst.end(); it++){
            s += to_string(*it);
        }
        int num = stoi(s);
        if (num > N){
            cout << num << '\n';
            return;
        }
    } while(next_permutation(lst.begin(), lst.end()));
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