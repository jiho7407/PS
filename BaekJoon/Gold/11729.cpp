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

int N;

void func(int n, int from, int to){
    // 종료조건
    // n이 1이면? 그냥 옮기면 끝
    if(n == 1){
        cout << from << ' ' << to << '\n';
        return;
    }

    // n이 2 이상이면?
    int buffer = 6 - from - to; // from, to가 아닌 다른 기둥
    func(n-1, from, buffer); // n-1개를 buffer로 옮긴다
    cout << from << ' ' << to << '\n'; // n번째를 to로 옮긴다
    func(n-1, buffer, to); // buffer에 있던 n-1개를 to로 옮긴다
}

void solve(){
    cin >> N;
    cout << (1<<N) - 1 << '\n';
    func(N, 1, 3);
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