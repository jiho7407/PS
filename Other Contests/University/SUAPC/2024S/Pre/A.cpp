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
    int N; cin >> N;
    if(N == 1){
        cout << "11" << '\n';
        cout << "A B C D E F G H J L M";
    }
    else if(N <= 4){
        cout << 9 << '\n';
        if(N == 2) cout << "A C E F G H I L M"; 
        if(N == 3) cout << "A C E F G H I L M"; 
        if(N == 4) cout << "A B C E F G H L M"; 
    }
    else{
        cout << 8 << '\n';
        if(N == 5) cout << "A C E F G H L M";
        if(N == 6) cout << "A C E F G H L M";
        if(N == 7) cout << "A C E F G H L M";
        if(N == 8) cout << "A C E F G H L M";
        if(N == 9) cout << "A C E F G H L M";
        if(N == 10) cout << "A B C F G H L M";
    }
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