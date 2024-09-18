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
vector<int> lst;

void solve(){
    cin >> N;
    lst.resize(N);
    for(int i=0; i<N; i++){
        cin >> lst[i];
    }
    sort(lst.begin(), lst.end());

    int ans = 0;
    for(int i = 0; i<N; i++){
        int l = 0, r = N-1; // 투포인터
        while(l < r){
            if(l == i){ // i번째수와 겹치면 안됨
                l++;
                continue;
            }
            if(r == i){
                r--;
                continue;
            }

            int sum = lst[l] + lst[r];
            if(sum == lst[i]){ // 합이 같으면
                ans++;
                break;
            }
            else if(sum < lst[i]) l++; // 합이 작으면 l을 늘림
            else r--;
        }
    }

    cout << ans;
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