#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
using namespace std;
typedef pair<int, int> pii;


void fastio(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
}

int N;
vector<tuple<int, bool, int>> points; // 좌표, 끝점여부, 인덱스
int ans = 0;
set<int> anset;

void solve(){
    cin >> N;
    rep(i, 1, N+1){
        int a, b;
        cin >> a >> b;
        points.push_back({a, false, i});
        points.push_back({b, true, i});
    }
    sort(points.begin(), points.end());
    int cnt = 0;
    for(auto [point, isEnd, idx] : points){
        if(isEnd){
            cnt--;
        }else{
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << '\n';

    cnt = 0;
    for(auto [point, isEnd, idx] : points){
        if(isEnd){
            cnt--;
            anset.erase(idx);
        }else{
            cnt++;
            anset.insert(idx);
        }
        if(cnt == ans){
            for(auto i : anset){
                cout << i << ' ';
            }
            cout << '\n';
            return;
        }
    }
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