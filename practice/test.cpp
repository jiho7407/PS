#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

vector<int> v = {1, 3, 10, 15, 20};

void solve(){
    auto it = upper_bound(v.begin(), v.end(), 6);
    cout << *it << '\n';
    cout << it - v.begin() << '\n';
    return;
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