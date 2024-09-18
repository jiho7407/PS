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

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n), brr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];

    map<pii, > mp1, mp2, mp3;
    mp1[{arr[0], brr[0]}] = 1;
    mp2[{brr[0], arr[0]}] = 1;

    for(int i = 1; i < n; i++){
        map<pii, int> nxt1, nxt2, nxt3;
        for(auto x : mp1){
            nxt1[{gcd(x.first.first, arr[i]), gcd(x.first.second, brr[i])}] += x.second;
            nxt2[{gcd(x.first.first, brr[i]), gcd(x.first.second, arr[i])}] += x.second;
        }
        for(auto x : mp2){
            nxt2[{gcd(x.first.first, brr[i]), gcd(x.first.second, arr[i])}] += x.second;
            nxt3[{gcd(x.first.first, arr[i]), gcd(x.first.second, brr[i])}] += x.second;
        }
        for(auto x : mp3){
            nxt3[{gcd(x.first.first, arr[i]), gcd(x.first.second, brr[i])}] += x.second;
        }
        mp1 = nxt1;
        mp2 = nxt2;
        mp3 = nxt3;
    }

    ll mx = 0, cnt = 0;
    for(auto i : mp2){
        if(i.first.first + i.first.second > mx){
            mx = i.first.first + i.first.second;
            cnt = i.second;
        } else if(i.first.first + i.first.second == mx){
            cnt += i.second;
        }
    }
    for(auto i : mp3){
        if(i.first.first + i.first.second > mx){
            mx = i.first.first + i.first.second;
            cnt = i.second;
        } else if(i.first.first + i.first.second == mx){
            cnt += i.second;
        }
    }
    cout << mx << ' ' << cnt << endl;
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