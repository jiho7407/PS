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
    vector<tuple<int, bool, int>> V; // {time, is_start}
    rep(i, 0, N){
        int a, b; cin >> a >> b;
        V.push_back({a, 1, a});
        V.push_back({b, 0, a});
    }
    sort(V.begin(), V.end());
    int s1 = 0, s2 = 0;


    int on = 0;
    vector<int> pfs(200010, 0);
    int last = 0;
    for(auto [b, is_start, a]: V){
        while(last < b){
            pfs[last+1] = pfs[last];
            last++;
        }
        if(is_start){
            on++;
            s2 = max(s2, on);
        }else{
            on--;
            pfs[b]++;
            s1 = max(s1, on + pfs[b] - pfs[a]);
        }
    }
    cout << s1 << ' ' << s2 << '\n';
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